#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
using namespace std;
int board[100002];
int via[100002];
main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int dx[4] = {1, 0, -1, 0};
    //int dy[4] = {0, 1, 0, -1};
    int width = 10;
    ///int height = 10;
    int me,sister=0;
    cin>>me>>sister;
    if(me==sister)
        cout<<"0";
    via[me]=1;
    queue<int> for_via_queue;
    for_via_queue.push(me);
    while (!for_via_queue.empty())
    {
        int x = for_via_queue.front();
        for_via_queue.pop();

        for (int i = 0; i < 3; i++)////
        {
            int qx;
            if(i==0)
                qx=x+1;
            else if(i==1)
                qx=x-1;
            else
                qx=x*2;
            if (qx >= 100001 || qx < 0)
                continue;
            if (via[qx] >= 1) // 
                continue;
            via[qx] = via[x]+1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
            for_via_queue.push(qx);
            if(qx==sister)
            {
                cout<<via[x];
                return 0;
            }
        }
    }

    return 0;
}