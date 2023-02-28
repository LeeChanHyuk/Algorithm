#include <iostream>
#include <vector>

using namespace std;

int via[50][50] = {0};
int board[50][50] = {0};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(vector<int> x_pos_vec, vector<int> y_pos_vec)
{
    vector<pair<int, int>> queue;
    int result = 0;
    while(!x_pos_vec.empty())
    {
        int x_pos = x_pos_vec.back();
        int y_pos = y_pos_vec.back();
        x_pos_vec.pop_back();
        y_pos_vec.pop_back();
        if(via[y_pos][x_pos] != 0)
            continue;
        result += 1;
        queue.push_back({y_pos, x_pos});
        via[y_pos][x_pos] = 1;

        while(!queue.empty())
        {
            y_pos, x_pos = queue[0].first, queue[0].second;
            queue.pop_back();
            for(int i=0; i<4; i++)
            {
                int dest_y = y_pos + dy[i];
                int dest_x = x_pos + dx[i];
                if(dest_y>50 || dest_x>50 || dest_x < 1 || dest_y < 1)
                    continue;
                else if(via[dest_y][dest_x] > 0)
                    continue;
                via[dest_y][dest_x] = 1;
                queue.push_back({dest_y, dest_x});
            }
        }
    }
}

int main()
{
    int T = 0;
    int M = 0; 
    int N = 0;
    int K = 0;
    vector<int> x_pos_vec;
    vector<int> y_pos_vec;
    scanf("%d", &T);
    scanf("%d %d %d", &M, &N, &K);
    int x_pos = 0;
    int y_pos = 0;
    for(int t=0; t<T; t++)
    {
        for(int i=0; i<K; i++)
        {   
            scanf("%d %d", &x_pos, &y_pos);
            x_pos_vec.push_back(x_pos);
            y_pos_vec.push_back(y_pos);
            board[y_pos][x_pos] = 1;
        }
        int result = bfs(x_pos_vec, y_pos_vec);
        printf("%d\n", result);
    }

    return 0;
}