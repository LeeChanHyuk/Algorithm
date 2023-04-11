#include <string.h>
#include <iostream>
#include <deque>

using namespace std;

int via[100002] = {0};
int dx[3] = {2, 1, -1};

int bfs(int subin, int sister)
{
    deque<int> bfs_deque;
    via[subin] = 1;
    bfs_deque.push_back(subin);
    int original_x = 0;
    int dest_x = 0;
    int result = 0;
    while(!bfs_deque.empty())
    {
        original_x = bfs_deque.front();
        bfs_deque.pop_front();
        for (int i=0; i<(sizeof(dx)/sizeof(int)); i++)
        {
            if (i == 0)
                dest_x = original_x * 2;
            else
                dest_x = original_x + dx[i];
            if (dest_x > 100000 || dest_x < 0)
                continue;
            else if (via[dest_x] > 0)
                continue;
            else if (dest_x == sister)
            {
                result = via[original_x] + 1;
                bfs_deque.clear();
                break;
            }
            via[dest_x] = via[original_x] + 1;
            bfs_deque.push_back(dest_x);
        }
    }
    return result;
}

int main(void)
{
    int subin, sister;
    scanf("%d %d", &subin, &sister);
    if (subin == sister)
        printf("%d\n", 0);
    else
    {
        int result = bfs(subin, sister);
        printf("%d\n", result-1);
    }
    return 0;
}