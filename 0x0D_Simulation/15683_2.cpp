#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

// 순서는 오 아래 왼 위 순번이다.
int width, height;
int small = 999;

vector<pair<int, int>> cctv_numbers;
vector<pair<int, int>> cctv_positions;
int cctv_number_flag[8];
int cctv_direction_flag[8]; // 초기화 안해도 전역변수로 선언하면 원래 0으로 초기화 되어 있다.
vector<int> out;

void direction(int board[8][8], int num, int x, int y, int step, bool board_reset)
{
    switch (num)
    {
    case 0: // 오른쪽
    {
        for (int i = x + 1; i < width && board[y][i] != 6; i++)
            board[y][i] = 7;
        break;
    }
    case 1: // 아래쪽
    {
        for (int i = y + 1; i < height && board[i][x] != 6; i++)
            board[i][x] = 7;
        break;
    }
    case 2: // 왼쪽
    {
        for (int i = x - 1; i > 0 && board[y][i] != 6; i--)
            board[y][i] = 7;
        break;
    }
    case 3: // 위쪽
    {
        for (int i = y - 1; i > 0 && board[y][i] != 6; i--)
            board[i][x] = 7;
    }
    }
}
void dfs(int step, int board[8][8])
{
    if (step == cctv_numbers.size())
    {
        int cnt = 0;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                if (board[i][j] == 0)
                    cnt++;
            }
        if (cnt < small)
            small = cnt;
        return;
    }
    int board_original[8][8];

    for (int i = 0; i < cctv_numbers.size(); i++)
    {
        if (cctv_number_flag[i] == 1)
            continue;
        cctv_number_flag[i] = 1;
        int num = cctv_numbers[i].first; // 어떤 CCTV 인지.
        int col = cctv_positions[i].second;
        int row = cctv_positions[i].first;
        for (int j = 0; j < cctv_numbers[i].second; j++)
        {
            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
                    board_original[i][j] = board[i][j];
            if (num - 1 == 0)
            {
                switch (j)
                {
                case 0:
                {
                    direction(board_original, j, col, row, step, true);
                    break;
                }
                case 1:
                {
                    direction(board_original, j, col, row, step, true);
                    break;
                }
                case 2:
                {
                    direction(board_original, j, col, row, step, true);
                    break;
                }
                case 3:
                {
                    direction(board_original, j, col, row, step, true);
                    break;
                }
                }
            }
            else if (num - 1 == 1)
            {
                switch (j)
                {
                case 0:
                {
                    {
                        direction(board_original, 0, col, row, step, true);
                        direction(board_original, 2, col, row, step, false);
                        break;
                    }
                }
                case 1:
                {
                    {
                        direction(board_original, 1, col, row, step, true);
                        direction(board_original, 3, col, row, step, false);
                        break;
                    }
                }
                }
            }
            else if (num - 1 == 2)
            {
                switch (j)
                {
                case 0:
                {
                    direction(board_original, 2, col, row, step, true);
                    direction(board_original, 3, col, row, step, false);

                    break;
                }
                case 1:
                {
                    direction(board_original, 3, col, row, step, true);
                    direction(board_original, 0, col, row, step, false);
                    break;
                }
                case 2:
                {
                    direction(board_original, 0, col, row, step, true);
                    direction(board_original, 1, col, row, step, false);
                    break;
                }
                case 3:
                {
                    direction(board_original, 1, col, row, step, true);
                    direction(board_original, 2, col, row, step, false);
                    break;
                }

                default:
                    break;
                }
            }
            else if (num - 1 == 3)
            {
                switch (j)
                {
                case 0:
                {
                    direction(board_original, 0, col, row, step, true);
                    direction(board_original, 1, col, row, step, false);
                    direction(board_original, 2, col, row, step, false);
                    break;
                }
                case 1:
                {
                    direction(board_original, 1, col, row, step, true);
                    direction(board_original, 2, col, row, step, false);
                    direction(board_original, 3, col, row, step, false);
                    break;
                }
                case 2:
                {
                    direction(board_original, 2, col, row, step, true);
                    direction(board_original, 3, col, row, step, false);
                    direction(board_original, 0, col, row, step, false);
                    break;
                }
                case 3:
                {
                    direction(board_original, 3, col, row, step, true);
                    direction(board_original, 0, col, row, step, false);
                    direction(board_original, 1, col, row, step, false);
                    break;
                }

                default:
                    break;
                }
            }
            else if (num - 1 == 4)
            {
                switch (j)
                {
                case 0:
                {
                    direction(board_original, 0, col, row, step, true);
                    direction(board_original, 1, col, row, step, false);
                    direction(board_original, 2, col, row, step, false);
                    direction(board_original, 3, col, row, step, false);
                    break;
                }

                default:
                    break;
                }
            }
            dfs(step + 1, board_original);
        }
        cctv_number_flag[i] = 0;
    }
}

int main(void)
{
    int board_original[8][8];
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> height >> width;
    int wall = 0;
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
            else if (board_original[i][j] == 6)
                wall++;
        }
    dfs(0, board_original);
    cout << small;
}