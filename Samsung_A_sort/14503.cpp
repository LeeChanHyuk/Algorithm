#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int board[50][50];
int via[50][50];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<pair<int, int>, int>> for_via_queue;
    int height, width;
    cin >> height >> width;
    int x, y, direction;
    cin >> y >> x >> direction;
    if (direction == 1)
        direction = 3;
    else if (direction == 3)
        direction = 1;
    for_via_queue.push({{y, x}, direction});
    via[y][x] = 1;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cin >> board[i][j];
    // 0 북 1 서 2 남 3 동
    bool machine_stop = false;
    while (!for_via_queue.empty() && !machine_stop)
    {
        bool back = true;
        x = for_via_queue.front().first.second;
        y = for_via_queue.front().first.first;
        direction = for_via_queue.front().second;

        for_via_queue.pop();
        do
        {
            back = true;
            for (int i = 0; i < 4; i++)
            {
                int direct = ((direction + 1 + i) % 4);
                int qx = x + dx[direct];
                int qy = y + dy[direct];
                if (qx >= width || qy >= height || qx < 0 || qy < 0)
                    continue;
                if (via[qy][qx] == 1 || board[qy][qx] == 1)
                    continue;
                for_via_queue.push({{qy, qx}, direct});
                via[qy][qx] = 1;
                back = false;
                break;
            }
            if (back)
            {
                x -= dx[direction];
                y -= dy[direction];
                if (board[y][x] == 1)
                {
                    machine_stop = true;
                    break;
                }
            }
        } while (back);
    }
    int sum = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            if (via[i][j] == 1 && board[i][j]==0)
                sum++;
        }
    cout << sum;

    return 0;
}