#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int board_original[8][8];
int board[8][8][8];
// 순서는 오 아래 왼 위 순번이다.
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int width, height;

vector<pair<int, int>> cctv_numbers;
vector<pair<int, int>> cctv_positions;
int cctv_number_flag[8];
int cctv_direction_flag[8]; // 초기화 안해도 전역변수로 선언하면 원래 0으로 초기화 되어 있다.
vector<int> out;

int direction(int num, int x, int y, int step)
{
    if (step == 0)
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                board[0][i][j] = board_original[i][j];
    }
    else
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                board[step][i][j] = board[step - 1][i][j];
    }
    switch (num)
    {
    case 0: // 오른쪽
    {
        int qx;
        while (1)
        {
            qx = x + 1;
            if (board[step][y][qx] == 6 || qx >= width)
                break;
            if (board[step][y][qx] == 0)
                board[step][y][qx] = 7;
        }
    }
    case 1: // 아래쪽
    {
        int qy;
        while (1)
        {
            qy = y + 1;
            if (board[step][qy][x] == 6 || qy >= height)
                break;
            if (board[step][qy][x] == 0)
                board[step][qy][x] = 7;
        }
    }
    case 2: // 왼쪽
    {
        int qx;
        while (1)
        {
            qx = x - 1;
            if (board[step][y][qx] == 6)
                break;
            if (board[step][y][qx] == 0)
                board[step][y][qx] = 7;
        }
    }
    case 3: // 위쪽
    {
        int qy;
        while (1)
        {
            qy = y - 1;
            if (board[step][qy][x] == 6)
                break;
            if (board[step][qy][x] == 0)
                board[step][qy][x] = 7;
        }
    }
    }
}

void dfs(int step)
{
    if (step == cctv_numbers.size())
    {
        int cnt = 0;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                if (board[cctv_numbers.size() - 1][i][j] == 7)
                    cnt++;
            }
        out.push_back(cnt);
    }
    for (int i = 0; i < cctv_numbers.size(); i++)
    {
        if (cctv_number_flag[i] == 1)
            continue;
        cctv_number_flag[i] = 1;
        int num = cctv_numbers[i].first; // 어떤 CCTV 인지.
        for (int j = 0; j < cctv_numbers[i].second; j++)
        {
            if (cctv_direction_flag[i] > j)
                continue;
            cctv_direction_flag[i]++;
            if (i == 0)
            {
                switch (j)
                {
                case 0:
                {
                    direction(j, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 1:
                {
                    direction(j, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 2:
                {
                    direction(j, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 3:
                {
                    direction(j, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                }
            }
            else if (i == 1)
            {
                switch (j)
                {
                case 0:
                {
                    {
                        direction(0, cctv_positions[i].second, cctv_positions[i].first, step);
                        direction(2, cctv_positions[i].second, cctv_positions[i].first, step);
                        break;
                    }
                }
                case 1:
                {
                    {
                        direction(1, cctv_positions[i].second, cctv_positions[i].first, step);
                        direction(3, cctv_positions[i].second, cctv_positions[i].first, step);
                        break;
                    }
                }
                }
            }
            else if (i == 2)
            {
                switch (j)
                {
                case 0:
                {
                    direction(2, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(3, cctv_positions[i].second, cctv_positions[i].first, step);

                    break;
                }
                case 1:
                {
                    direction(3, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(0, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 2:
                {
                    direction(0, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(1, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 3:
                {
                    direction(1, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(2, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }

                default:
                    break;
                }
            }
            else if (i == 3)
            {
                switch (j)
                {
                case 0:
                {
                    direction(0, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(1, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(2, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 1:
                {
                    direction(1, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(2, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(3, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 2:
                {
                    direction(2, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(3, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(0, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }
                case 3:
                {
                    direction(3, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(0, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(1, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }

                default:
                    break;
                }
            }
            else if (i == 4)
            {
                switch (j)
                {
                case 0:
                {
                    direction(0, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(1, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(2, cctv_positions[i].second, cctv_positions[i].first, step);
                    direction(3, cctv_positions[i].second, cctv_positions[i].first, step);
                    break;
                }

                default:
                    break;
                }
            }
            dfs(step + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> height >> width;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            cin >> board_original[i][j];
            if (board_original[i][j] == 1)
            {
                cctv_numbers.push_back({1, 4});
                cctv_positions.push_back({i, j});
            }
            else if (board_original[i][j] == 2)
            {
                cctv_numbers.push_back({2, 2});
                cctv_positions.push_back({i, j});
            }
            else if (board_original[i][j] == 3)
            {
                cctv_numbers.push_back({3, 4});
                cctv_positions.push_back({i, j});
            }
            else if (board_original[i][j] == 4)
            {
                cctv_numbers.push_back({4, 4});
                cctv_positions.push_back({i, j});
            }
            else if (board_original[i][j] == 5)
            {
                cctv_numbers.push_back({5, 1});
                cctv_positions.push_back({i, j});
            }
        }
    dfs(0);
    int min = 99999;
    for (int i = 0; i < out.size(); i++)
        if (min > out[i])
            min = out[i];
    cout << min;
}