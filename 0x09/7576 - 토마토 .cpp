#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;
int board[1002][1002];
int via[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int width = 10;
    int height = 10;
    cin>>width>>height;
    queue<pair<int, int>> for_via_queue;
    int minus_one_num = 0;
    int one_number = 0;
    int goal=0;
    int max=0;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            cin>>board[i][j];
            if(board[i][j] == 1)
            {
                for_via_queue.push({j,i});
                via[i][j] = 1;
                one_number++;
            }
            if(board[i][j] == -1)
                minus_one_num++;
        }
    }
    goal = (height*width) - minus_one_num; // one number가 goal이 되면 완성!
    if(one_number == goal)
    {
        cout<<"0";
        return 0;
    }

    
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
            if (via[qy][qx] >= 1 || board[qy][qx] != 0) // 방문해보면 무조건 1 이상이니까 안되고 // board는 1 or -1 전부 안된다.
                continue;
            via[qy][qx] = via[y][x]+1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
            if(via[qy][qx]>max)
                max=via[qy][qx];
            one_number++;
            if(one_number == goal)
                cout<<max-1;
            for_via_queue.push({qx, qy});
        }
    }
    if(one_number != goal)
        cout << "-1";

    return 0;
}