#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int board[100][100];
int width, height;
int apple_num;
int direction_num;
int now_time = 0;
vector<pair<int, char>> snake_direction;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;

struct snake
{
    queue<pair<int, int>> position;
    int direction; // 0 right 1 down 2 left 3 up
};

void move()
{
    snake snake;
    snake.direction = 0;
    snake.position.push({0, 0});
    int direction_num = 0;
    while (result == 0)
    {
        int head_x = snake.position.back().second + dx[snake.direction];
        int head_y = snake.position.back().first + dy[snake.direction];
        int tail_x = snake.position.front().second;
        int tail_y = snake.position.front().first;
        now_time++;

        if (head_x >= width || head_y >= height || head_x < 0 || head_y < 0 || board[head_y][head_x] == 1)
        {
            result = now_time;
            break;
        }                                      //자기 자신이랑 만날 가능성도 체크 완료.
        snake.position.push({head_y, head_x}); // push new position (relevant head)
        //now, we must insert 1 for new position(head) and delete old position(tail) if snake didn't take apple.
        if (board[head_y][head_x] != 20000) // no apple
        {
            board[tail_y][tail_x] = 0;
            snake.position.pop(); // delete top (tail position);
        }
        board[head_y][head_x] = 1;
        if (snake_direction[direction_num].first == now_time)
        {
            if (snake_direction[direction_num].second == 'D')
                if (snake.direction == 3)
                    snake.direction = 0;
                else
                {
                    snake.direction += 1;
                }
            else
            {
                if (snake.direction == 0)
                    snake.direction = 3;
                else
                {
                    snake.direction -= 1;
                }
            }
            direction_num++;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> width >> apple_num;
    height = width;
    for (int i = 0; i < apple_num; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = 20000; // 20000 is apple coordinates.
    }
    cin >> direction_num;
    for (int i = 0; i < direction_num; i++)
    {
        int time;
        char dir;
        cin >> time >> dir;
        snake_direction.push_back({time, dir});
    }
    board[0][0] = 1;
    move();
    cout << result;

    return 0;
}