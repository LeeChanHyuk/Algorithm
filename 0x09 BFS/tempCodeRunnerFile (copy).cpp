#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;
int board[52][52];
int via[52][52];
main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int width = 10;
    int height = 10;
    int command_num=0;
    cin>>command_num;
    for(int cases; cases<command_num; cases++)
    {

    
    queue<pair<int, int>> for_via_queue;
    via[0][0] = 1; // 파란칸이면 1로 표기.
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
            if (via[qx][qy] == 1 || board[qx][qy] != 1)
                continue;
            via[qx][qy] = 1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
            for_via_queue.push({qx, qy});
        }
    }
    }

    return 0;
}