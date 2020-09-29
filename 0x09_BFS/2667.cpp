#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string board[30];
int via[30][30];

int main(void)
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    queue<pair<int,int>> queue_for_via;
    int width;
    cin>>width;
    int num=0;
    int area=0;
    vector<int> areas;
    for(int i=0; i<width; i++)
    {
        cin>>board[i];
    }
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(board[i][j] == '0' || via[i][j] == 1)
                continue;
            via[i][j]=1;
            queue_for_via.push({i,j});
            num++;
            while(!queue_for_via.empty())
            {
                int y= queue_for_via.front().first;
                int x = queue_for_via.front().second;
                queue_for_via.pop();
                // 여기는 집의 넓이를 구해야지
                area++;
                for(int k=0; k<4; k++)
                {
                    int qx = x+dx[k];
                    int qy = y+dy[k];
                    if(qx>=width ||qy>=width || qx<0 || qy<0)
                        continue;
                    if(board[qy][qx]=='0')
                        continue;
                    if(via[qy][qx]==1)
                        continue;
                    via[qy][qx]=1;
                    queue_for_via.push({qy,qx});
                    
                }
            }
            areas.push_back(area);
            area=0;
        }
    }
    cout<<num<<'\n';
    sort(areas.begin(),areas.end());
    for(int i=0; i<num; i++)
    {
        cout<<areas[i]<<'\n';
    }
	return 0;
}