#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#pragma warning(disable : 4996)
#define X first
#define Y second
using namespace std;
string board[102];
int via[102][102];  // 적록색약 아닌사람
int via2[102][102]; // 적록색약인사뢈.

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int command_num = 0;
    int width = 0;
    int height = 0;
    cin >> width;
    for (int i = 0; i < width; i++)
        cin >> board[i];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int num1 = 0, num2 = 0;
    queue<pair<int, int>> queue_for_via;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (via[i][j] == 1)
                continue;
            queue_for_via.push({i, j});
            via[i][j] = 1;
            num1++;
            while (!queue_for_via.empty())
            {
                int y = queue_for_via.front().first;
                int x = queue_for_via.front().second;
                char RGB = board[y][x];
                queue_for_via.pop();
                for (int k = 0; k < 4; k++)
                {
                    int qx = x + dx[k];
                    int qy = y + dy[k];
                    if (qx >= width || qy >= width || qx < 0 || qy < 0)
                        continue;
                    if (via[qy][qx] == 1 || RGB != board[qy][qx])
                        continue;
                    via[qy][qx] = 1;
                    queue_for_via.push({qy, qx});
                }
            }
        }
    }
    queue<pair<int, int>> queue_for_via2;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (via2[i][j] == 1)
                continue;
            queue_for_via2.push({i, j});
            via2[i][j] = 1;
            num2++;
            while (!queue_for_via2.empty())
            {
                int y = queue_for_via2.front().first;
                int x = queue_for_via2.front().second;
                char RGB = board[y][x];
                queue_for_via2.pop();
                for (int k = 0; k < 4; k++)
                {
                    int qx = x + dx[k];
                    int qy = y + dy[k];
                    if (qx >= width || qy >= width || qx < 0 || qy < 0)
                        continue;
                    if (via2[qy][qx] == 1)
                        continue;
                    if (RGB == 'B' && RGB != board[qy][qx])
                        continue;
                    if ((RGB == 'R' || RGB == 'G') && (board[qy][qx] != 'R' && board[qy][qx] != 'G'))
                        continue;
                    via2[qy][qx] = 1;
                    queue_for_via2.push({qy, qx});
                }
            }
        }
    }
    cout << num1 << " " << num2;
    return 0;
}