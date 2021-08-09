#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

char board[10][10];
int via[10][10][10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int mins = 999;
bool finish = false;
int result1, result2, result3, result4;
queue<pair<int, int>> blue_queue;
queue<pair<int, int>> red_queue;
struct blue
{
    int x, y, offset, direction;
};
struct red
{
    int x, y, offset, direction;
};
struct hole
{
    int x, y;
    int result1, result2, result3, result4;
};

void bfs(hole hole)
{
    while (!red_queue.empty() && finish != true)
    {
        int red_y = red_queue.front().first;
        int red_x = red_queue.front().second;
        int blue_y = blue_queue.front().first;
        int blue_x = blue_queue.front().second;
        red_queue.pop();
        blue_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            int red_qy = red_y;
            int red_qx = red_x;
            int blue_qy = blue_y;
            int blue_qx = blue_x;
            int red_count = 0;
            int blue_count = 0;
            while (board[red_qy][red_qx] != '#' && board[red_qy][red_qx] != 'O')
            {
                red_qy += dy[i];
                red_qx += dx[i];
                red_count++;
            }
            while (board[blue_qy][blue_qx] != '#' && board[blue_qy][blue_qx] != 'O')
            {
                blue_qy += dy[i];
                blue_qx += dx[i];
                blue_count++;
            }
            if (blue_qy == hole.y && blue_qx == hole.x)
                continue;
            if (red_qy == hole.y && red_qx == hole.x)
                if (mins > via[red_y][red_x][blue_y][blue_x] + 1)
                {
                    mins = via[red_y][red_x][blue_y][blue_x] + 1;
                    finish = true;
                    result1 = red_qy;
                    result2 = red_qx;
                    result3 = blue_qy;
                    result4 = blue_qx;
                    break;
                }
            red_qy -= dy[i];
            red_qx -= dx[i];
            blue_qy -= dy[i];
            blue_qx -= dx[i];
            if (red_qx == blue_qx && red_qy == blue_qy)
                if (red_count > blue_count)
                {
                    red_qy -= dy[i];
                    red_qx -= dx[i];
                }
                else
                {
                    blue_qy -= dy[i];
                    blue_qx -= dx[i];
                }
            if (via[red_qy][red_qx][blue_qy][blue_qx] >= 1)
                continue;
            via[red_qy][red_qx][blue_qy][blue_qx] = via[red_y][red_x][blue_y][blue_x] + 1;
            red_queue.push({red_qy, red_qx});
            blue_queue.push({blue_qy, blue_qx});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int height, width;
    cin >> height >> width;
    red red;
    blue blue;
    hole holes;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'O')
            {
                holes.x = j;
                holes.y = i;
            }
            else if (board[i][j] == 'R')
            {
                red.x = j;
                red.y = i;
            }
            else if (board[i][j] == 'B')
            {
                blue.x = j;
                blue.y = i;
            }
        }
    red_queue.push({red.y, red.x});
    blue_queue.push({blue.y, blue.x});
    via[red.y][red.x][blue.y][blue.x] = 1;
    bfs(holes);

    if (mins == 999)
        cout << "-1";
    else
    {
        if (mins > 11)
            cout << "-1";
        else
            cout << mins - 1;
    }
    return 0;
}