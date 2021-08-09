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
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int width = 10;
    int height = 10;
    int command_num = 0;
    cin >> command_num;
    int cabbage_num = 0;

    for (int cases=0; cases < command_num; cases++)
    {
        int positions = 0;
        cin >> width >> height >> positions;
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                board[i][j]=0;
                via[i][j]=0;
            }
        }
        for (int position = 0; position < positions; position++)
        {
            int x, y = 0;
            cin >> x >> y;
            board[y][x]++;
        }
        queue<pair<int, int>> for_via_queue;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (board[i][j] == 1 && via[i][j] != 1)
                {
                    
                    for_via_queue.push({j, i});
                    cabbage_num++;
                    via[i][j] = 1; // 파란칸이면 1로 표기.
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
                            if (via[qy][qx] == 1 || board[qy][qx] != 1)
                                continue;
                            via[qy][qx] = 1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
                            for_via_queue.push({qx, qy});
                        }
                    }
                }
            }
        }
        cout << cabbage_num<<'\n';
        cabbage_num = 0;
    }

    return 0;
}