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
string board[1002];
int via[1002][1002][2];

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
    for (int i = 0; i < height; i++)
        cin >> board[i];
    queue<pair<pair<int, int>, int>> for_via_queue;
    bool did = false;
    // 1은 아직 벽 뚫을 수 있는 것
    via[0][0][1] = 1;
    for_via_queue.push({{0, 0}, 1});
    while (!for_via_queue.empty())
    {
        int x = for_via_queue.front().first.second;
        int y = for_via_queue.front().first.first;
        int z = for_via_queue.front().second;
        if (x == width - 1 && y == height - 1)
        {
            cout << via[y][x][z];
            did = true;
            break;
        }
        for_via_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            int qx = x + dx[i];
            int qy = y + dy[i];
            if (qx >= width || qy >= height || qx < 0 || qy < 0)
                continue;
            if(via[qy][qx][1]>=1)
                continue;
            if (board[qy][qx] == '1' && z == 1) // 벽이 있고, 뚫을 수 있을 때, z==1이라는건 벽에는 가본적이 없다는 뜻.)
            {
                via[qy][qx][0] = via[y][x][z] + 1;
                for_via_queue.push({{qy, qx}, 0});
            }
            if (board[qy][qx] == '0' && via[qy][qx][z] == 0) // z==1일때에는 0에 대한 체크필요 X. 0이 0이든 1이든 방문해봐야함.(더 많은경로)
            {
                via[qy][qx][z] = via[y][x][z] + 1;
                for_via_queue.push({{qy, qx}, z});
            }
        }
    }
    if (!did)
        cout << "-1";
    return 0;
}