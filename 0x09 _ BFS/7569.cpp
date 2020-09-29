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
int board[102][102][102];
int via[102][102][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[6] = {1, 0, -1, 0,0,0};
    int dy[6] = {0, 1, 0, -1,0,0};
    int dz[6] = {0,0,0,0,1,-1};
    int width = 10;
    int height = 10;
    int depth = 10;
    cin>>width>>height>>depth;
    queue<pair<pair<int, int>,int>> for_via_queue;
    int minus_one_num = 0;
    int one_number = 0;
    int goal=0;
    int max=0;
    for(int k=0; k<depth; k++)
    {
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                cin>>board[i][j][k];
                if(board[i][j][k] == 1)
                {
                    for_via_queue.push({{j,i},k});
                    via[i][j][k] = 1;
                    one_number++;
                }
                if(board[i][j][k] == -1)
                    minus_one_num++;
            
            }
        }
    }
    goal = (height*width*depth) - minus_one_num; // one number가 goal이 되면 완성!
    if(one_number == goal)
    {
        cout<<"0";
        return 0;
    }

    
    while (!for_via_queue.empty())
    {
        int x = for_via_queue.front().first.X;
        int y = for_via_queue.front().first.Y;
        int z = for_via_queue.front().second;
        for_via_queue.pop();

        for (int i = 0; i < 6; i++)
        {
            int qx = x + dx[i];
            int qy = y + dy[i];
            int qz = z + dz[i];
            if (qx >= width || qy >= height || qx < 0 || qy < 0 ||qz<0 || qz>=depth)
                continue;
            if (via[qy][qx][qz] >= 1 || board[qy][qx][qz] != 0) // 방문해보면 무조건 1 이상이니까 안되고 // board는 1 or -1 전부 안된다.
                continue;
            via[qy][qx][qz] = via[y][x][z]+1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
            if(via[qy][qx][qz]>max)
                max=via[qy][qx][qz];
            one_number++;
            if(one_number == goal)
                cout<<max-1;
            for_via_queue.push({{qx, qy},qz});
        }
    }
    if(one_number != goal)
        cout << "-1";

    return 0;
}