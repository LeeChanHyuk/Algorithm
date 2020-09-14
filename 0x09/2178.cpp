#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <stdio.h>
#define X second
#define Y first
using namespace std;
int board[502][502];
int main(void)
{
    int via[502][502];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int width = 10;
    int height = 10;
    scanf("%d %d", &height, &width); // \n을 만나기 전까지만 읽어오기 때문에 읽어오고나서 입력버퍼에 \n이 남아있다.
    char a = getchar(); // 개행문자 처리용
    char line[101];
    for (int i = 0; i < height; i++)
    {
        fgets(line,101,stdin);
        for (int j = 0; j < width; j++)
        {
            board[i][j] = (int)line[j] - 48;
        }
    }
    int max = 99999;
    queue<pair<int, int>> for_via_queue;
    via[0][0] = 1;
    for_via_queue.push({0, 0});
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
            if (board[qy][qx] != 1)
                continue;
            if (via[qy][qx] >= 0) // 0이 아니라는 것-> 무언가 들어왔을 때, 원래꺼보다 더 크다면 더 돌아온 것.
                continue;
            via[qy][qx] = via[y][x] + 1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
            for_via_queue.push({qy, qx});
        }
    }
    printf("%d", via[height-1][width-1]+1);
    return 0;
}