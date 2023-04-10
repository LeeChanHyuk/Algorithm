#include <iostream>
#include <deque>
#include <stdio.h>
#include <string.h>

using namespace std;

int via[51][51] = {0};
int board[51][51] = {0};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(deque<int> x_pos_vec, deque<int> y_pos_vec)
{
    deque<pair<int, int>> queue;
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
            y_pos = queue[0].first;
            x_pos = queue[0].second;
            queue.pop_front();
            for(int i=0; i<4; i++)
            {
                int dest_y = y_pos + dy[i];
                int dest_x = x_pos + dx[i];
                if(dest_y>=50 || dest_x>=50 || dest_x < 0 || dest_y < 0)
                    continue;
                else if(via[dest_y][dest_x] > 0)
                    continue;
                else if(board[dest_y][dest_x] == 0)
                    continue;
                via[dest_y][dest_x] = 1;
                queue.push_back({dest_y, dest_x});
            }
        }
    }
    return result;
}

int main()
{
    int T = 0;
    int M = 0; 
    int N = 0;
    int K = 0;
    deque<int> x_pos_vec;
    deque<int> y_pos_vec;
    scanf("%d", &T);
    int x_pos = 0;
    int y_pos = 0;
    for(int t=0; t<T; t++)
    {
        x_pos_vec.clear();
        y_pos_vec.clear();
        memset(via, 0, sizeof(via));
        memset(board, 0, sizeof(board));
        scanf("%d %d %d", &M, &N, &K);
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