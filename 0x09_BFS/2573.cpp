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
int board[102][102];
int via[102][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int command_num = 0;
    int width = 0;
    int height = 0;
    cin >> height >> width;  
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int year=0;
    int num=0;
    queue<pair<int, int>> for_via_queue;
    while(1)
    {
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (via[i][j] == 1 || board[i][j]<=0)
                continue;
            via[i][j] = 1;
            for_via_queue.push({i, j});
            while (!for_via_queue.empty())
            {
                int x = for_via_queue.front().X;
                int y = for_via_queue.front().Y;
                int check = 0;
                for_via_queue.pop();

                for (int i = 0; i < 4; i++)
                {
                    int qx = x + dx[i];
                    int qy = y + dy[i];
                    if (board[qy][qx] <= 0)
                    {
                        check++;
                        continue;
                    }
                    if (qx >= height || qy >= width || qx < 0 || qy < 0)
                        continue;
                    if (via[qy][qx] == 1)
                        continue;
                    for_via_queue.push({qy, qx});
                    via[qy][qx] = 1;
                }
                if (check > 0)
                {
                    board[y][x] = board[y][x] - check;
                }
                check = 0;
            }
        }
    }
    }

    return 0;
}
