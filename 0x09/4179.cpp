#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#define X first
#define Y second
#define Z second
using namespace std;
string board[1002];
int via1[1002][1002];
int via2[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int width = 10;
    int height = 10;
    cin>>width>>height;
    queue<pair<int, int>>for_via_queue1;
    queue<pair<int,int>>for_via_queue2;
    for(int i=0; i<height; i++)
    {
        cin>>board[i];
    }

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(board[i][j] == 'F')
            {
                for_via_queue1.push({j,i});
                via1[i][j]=1;
            }
            if(board[i][j] == 'J')
            {
                for_via_queue2.push({j,i});
                if(i==0 || i==height-1 || j==0 || j==width-1)
                {
                    cout<<"1";
                    return 0;
                }
                via2[i][j] = 1;
            }
        }
    }


    while (!for_via_queue1.empty())
    {
        int x = for_via_queue1.front().X;
        int y = for_via_queue1.front().Y;
        for_via_queue1.pop();

        for (int i = 0; i < 4; i++)
        {
            int qx = x + dx[i];
            int qy = y + dy[i];
            if (qx >= width || qy >= height || qx < 0 || qy < 0)
                continue;
            if (via1[qy][qx] >= 1 || board[qy][qx] == '#') // 방문해보면 무조건 1 이상이니까 안되고 // board는 1 or -1 전부 안된다.
                continue;
            via1[qy][qx]= via1[y][x]+1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
            for_via_queue1.push({qx, qy});
        }
    }

    while(!for_via_queue2.empty())
    {
        int x = for_via_queue2.front().X;
        int y = for_via_queue2.front().Y;
        for_via_queue2.pop();
        for(int i=0; i<4; i++)
        {
            int qx = x+ dx[i];
            int qy = y+ dy[i];

            if(qx>=width || qy>=height || qx<0 || qy<0)
                continue;
            if(board[qy][qx] == '#' || via1[qy][qx]<=via2[y][x]+1 || via2[qy][qx]>=1)
                continue;
            via2[qy][qx] = via2[y][x]+1;
            if(qy == height-1 || qx == width-1 || qx==0 || qy==0)
            {
                cout<<via2[qy][qx];
                return 0;
            }
            for_via_queue2.push({qx,qy});
        }
    }
    cout<<"IMPOSSIBLE";

    return 0;
}