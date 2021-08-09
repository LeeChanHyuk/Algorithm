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
int board[102][102];
int via[102][102];
int num_arr[101];
int areas[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int command_num = 0;
    int width = 0;
    int height = 0;
    cin >> width;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<int> num_queue;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a;
            cin >> a;
            board[i][j] = a;
            if (num_arr[a] == 0)
            {
                num_arr[a]++;
                num_queue.push(a); // num_queue에는 들어간 숫자의 종류만이 담겨있다.
            }
        }
    }

    while (!num_queue.empty())
    {
        int num = num_queue.front();
        int area = 0;
        num_queue.pop();
        queue<pair<int, int>> for_via_queue;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (via[i][j] == 1 || board[i][j] <= num)
                    continue;
                via[i][j] = 1;
                for_via_queue.push({i, j});
                area++;
                while (!for_via_queue.empty())
                {
                    int x = for_via_queue.front().second;
                    int y = for_via_queue.front().first;
                    for_via_queue.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int qx = x + dx[i];
                        int qy = y + dy[i];
                        if (qx >= width || qy >= width || qx < 0 || qy < 0)
                            continue;
                        if (via[qy][qx] == 1 || board[qy][qx] <= num)
                            continue;
                        for_via_queue.push({qy, qx});
                        via[qy][qx] = 1;
                    }
                }
            }
        }
        memset(via, 0, sizeof(via));
        areas[num] = area;
    }
    int max = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (areas[i] > max)
            max = areas[i];
        if (max == 0)
            max = 1;
    }
    cout << max;
    return 0;
}