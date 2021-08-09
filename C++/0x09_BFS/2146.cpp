#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
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
    cin >> height;
    width = height;
    vector<vector<pair<int, int>>> one;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cin >> board[i][j];
    }

    queue<pair<int, int>> for_via_queue;
    int count = -1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (via[i][j] == 1 || board[i][j] == 0)
                continue;
            count++;
            vector<pair<int, int>> two;
            one.push_back(two);
            one[count].push_back({i, j});
            via[i][j] = 1;
            for_via_queue.push({i, j});
            while (!for_via_queue.empty())
            {
                int x = for_via_queue.front().second;
                int y = for_via_queue.front().first;
                for_via_queue.pop();

                for (int i = 0; i < 4; i++)
                {
                    int qx = x + dx[i];
                    int qy = y + dy[i];
                    if (qy >= height || qx >= width || qx < 0 || qy < 0)
                        continue;
                    if (via[qy][qx] == 1 || board[qy][qx] == 0)
                        continue;
                    for_via_queue.push({qy, qx});
                    via[qy][qx] = 1;
                    one[count].push_back({qy, qx});
                }
            }
        }
    }
    int dif = 99999;
    int x1, x2, y1, y2;
    for (int i = 0; i <= count; i++) // 어떤 나라를 고를건지
    {
        for (int j = 0; j < one[i].size(); j++)
        {
            x1 = one[i][j].second;
            y1 = one[i][j].first;
            for (int k = i + 1; k <= count; k++)
            {
                for (int l = 0; l < one[k].size(); l++)
                {
                    x2 = one[k][l].second;
                    y2 = one[k][l].first;
                    if (abs(x1 - x2) + abs(y1 - y2) < dif)
                        dif = abs(x1 - x2) + abs(y1 - y2);
                }
            }
        }
    }
    cout << dif-1;
    return 0;
}