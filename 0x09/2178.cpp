#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <stdio.h>
#define X second
#define Y first
using namespace std;
int via[502][502];
string board[502];
int main(void)
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int width = 10;
    int height = 10;
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> height >> width;
    for (int i = 0; i < height; i++)
        cin >> board[i];
    for (int i = 0; i < height; i++)
        fill(via[i], via[i] + width, -1);
    queue<pair<int, int>> for_via_queue;
    via[0][0] = 1;
    for_via_queue.push({0, 0});
    while (!for_via_queue.empty())
    {
        int x = for_via_queue.front().X;
        int y = for_via_queue.front().Y;
        for_via_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            int qx = x + dx[i];
            int qy = y + dy[i];
            if (qx >= width || qy >= height || qx < 0 || qy < 0)
                continue;
            if (board[qy][qx] != '1' || via[qy][qx] >= 0)
                continue;
            via[qy][qx] = via[y][x] + 1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
            for_via_queue.push({qy, qx});
        }
    }
    printf("%d", via[height - 1][width - 1]);
    return 0;
}