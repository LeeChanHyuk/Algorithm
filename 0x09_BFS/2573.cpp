#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#pragma warning(disable : 4996)
#include <string.h>
#define X first
#define Y second
using namespace std;
int board[302][302];
int board2[302][302];
int via[302][302];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int command_num = 0;
    int width = 0;
    int height = 0;
    cin >> height >> width;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cin >> board[i][j];
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int year = 0;
    int num = 0;
    queue<pair<int, int>> for_via_queue;
    while (1)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (via[i][j] == 1 || board[i][j] <= 0)
                    continue;
                num++;
                if (num >= 2)
                {
                    cout << year;
                    return 0;
                }
                via[i][j] = 1;
                for_via_queue.push({i, j});
                while (!for_via_queue.empty())
                {
                    int x = for_via_queue.front().second;
                    int y = for_via_queue.front().first;
                    int a = board[y][x];
                    int check = 0;
                    for_via_queue.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int qx = x + dx[i];
                        int qy = y + dy[i];
                        if (board[qy][qx] <= 0)
                        {
                            check--;
                            continue;
                        }
                        if (qy >= height || qx >= width || qx < 0 || qy < 0)
                            continue;
                        if (via[qy][qx] == 1)
                            continue;
                        for_via_queue.push({qy, qx});
                        via[qy][qx] = 1;
                    }

                    board2[y][x] = check;

                    check = 0;
                }
            }
        }
        if (num == 0)
        {
            cout << 0;
            return 0;
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                board[i][j] = board[i][j] + board2[i][j];
                board2[i][j] = 0;
            }
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        year++;
        memset(via, 0, sizeof(via));
        num = 0;
    }

    return 0;
}
