#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#define X second
#define Y first
using namespace std;
int board[502][502];
main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int via[502][502];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int width = 10;
    int height = 10;
    scanf("%d %d", &height, &width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            scanf("%d", &board[i][j]); // board 입력 받기
        }
    }
    queue<pair<int, int>> for_via_queue;
    int picture_number = 0;
    int max = 0;
    int now = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j] != 1 || via[i][j] == 1)
                continue;
            via[i][j] = 1;
            for_via_queue.push({i, j});
            picture_number++;
            while (!for_via_queue.empty())
            {
                int x = for_via_queue.front().X;
                int y = for_via_queue.front().Y;
                for_via_queue.pop();
                now++;
                for (int i = 0; i < 4; i++)
                {
                    int qx = x + dx[i];
                    int qy = y + dy[i];
                    if (qx >= width || qy >= height || qx < 0 || qy < 0)
                        continue;
                    if (via[qy][qx] == 1 || board[qy][qx] != 1)
                        continue;
                    via[qy][qx] = 1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
                    for_via_queue.push({qy, qx});
                }
            }
            if (now > max)
                max = now;
            now=0;

        }
    }
    printf("%d\n%d\n", picture_number, max);
    return 0;
}