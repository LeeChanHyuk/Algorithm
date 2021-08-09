#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#pragma warning(disable : 4996)
#define X first
#define Y second
using namespace std;
string board[1002];
int via_for_fire[1002][1002];
int via_for_dog[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int command_num = 0;
    int width = 0;
    int height = 0;
    cin >> command_num;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int k = 0; k < command_num; k++)
    {
        queue<pair<int, int>> for_via_queue_dog;
        queue<pair<int, int>> for_via_queue_fire;
        cin >> width >> height;

        for (int i = 0; i < height; i++)
        {
            cin >> board[i];
            for (int j = 0; j < width; j++)
            {
                if (board[i][j] == '*')
                {
                    for_via_queue_fire.push({i, j});
                    via_for_fire[i][j] = 1;
                }
                else if (board[i][j] == '@')
                {
                    for_via_queue_dog.push({i, j});
                    via_for_dog[i][j] = 1;
                }
            }
        }
        while (!for_via_queue_fire.empty())
        {
            int x = for_via_queue_fire.front().second;
            int y = for_via_queue_fire.front().first;
            for_via_queue_fire.pop();

            for (int i = 0; i < 4; i++)
            {
                int qx = x + dx[i];
                int qy = y + dy[i];
                if (qy >= height || qx >= width || qx < 0 || qy < 0)
                    continue;
                if (via_for_fire[qy][qx] >= 1 || board[qy][qx] == '#')
                    continue;
                for_via_queue_fire.push({qy, qx});
                via_for_fire[qy][qx] = via_for_fire[y][x] + 1;
            }
        }
        bool success = 0;
        while (!for_via_queue_dog.empty())
        {
            int x = for_via_queue_dog.front().second;
            int y = for_via_queue_dog.front().first;
            for_via_queue_dog.pop();
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
            {
                cout << via_for_dog[y][x] << '\n';
                success = 1;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int qx = x + dx[i];
                int qy = y + dy[i];
                if (qy >= height || qx >= width || qx < 0 || qy < 0)
                    continue;
                if (via_for_dog[qy][qx] >= 1 || board[qy][qx] == '#' || (via_for_fire[qy][qx] != 0 && via_for_fire[qy][qx] <= via_for_dog[y][x] + 1))
                    continue;
                for_via_queue_dog.push({qy, qx});
                via_for_dog[qy][qx] = via_for_dog[y][x] + 1;
            }
        }
        if (!success)
            cout << "IMPOSSIBLE" << '\n';
        memset(via_for_fire, 0, sizeof(via_for_fire));
        memset(via_for_dog, 0, sizeof(via_for_dog));
    }
    return 0;
}