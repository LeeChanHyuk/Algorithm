#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
// old1 is top, old2 is north, old3 is down, old4 is south
int top1 = 0, north1 = 0, down1 = 0, south1 = 0, left1 = 0, right1 = 0; // left1 is left, right1 is right
int top2, north2, down2, south2, left2, right2;
int board[20][20];
int x, y;

void dice_rolling(int direction)
{
    switch (direction)
    {
    case 1: // right direction
    {
        top2 = left1;    // top
        north2 = north1; // north
        down2 = right1;  // down
        south2 = south1; // south
        left2 = down1;   // left
        right2 = top1;   // right
        break;
    }
    case 4: // south direction
    {
        top2 = north1;   // top
        north2 = down1;  // north
        down2 = south1;  // down
        south2 = top1;   // south
        left2 = left1;   // left
        right2 = right1; // right
        break;
    }
    case 2: // left direction
    {
        top2 = right1;   // top
        north2 = north1; // north
        down2 = left1;   // down
        south2 = south1; // south
        left2 = top1;    // left
        right2 = down1;  // right
        break;
    }
    case 3: // north direction
    {
        top2 = south1;   // right
        north2 = top1;   // left
        down2 = north1;  // south
        south2 = down1;  // down
        left2 = left1;   // north
        right2 = right1; // top
        break;
    }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // know where is the down side and
    int height, width;
    cin >> height >> width;
    cin >> y >> x;
    int command_num;
    cin >> command_num;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cin >> board[i][j];
    while (command_num)
    {
        int command;
        cin >> command;
        switch (command)
        {
        case 1: // right
        {
            x += 1;
            if (x >= width || x < 0 || y >= height || y < 0)
            {
                x -= 1;
                break;
            }
            dice_rolling(1);
            if (board[y][x] == 0)
                board[y][x] = down2;
            else
            {
                down2 = board[y][x];
                board[y][x] = 0;
            }
            cout << top2 << '\n';
            break;
        }
        case 2: // left
        {
            x -= 1;
            if (x >= width || x < 0 || y >= height || y < 0)
            {
                x += 1;
                break;
            }
            dice_rolling(2);
            if (board[y][x] == 0)
                board[y][x] = down2;
            else
            {
                down2 = board[y][x];
                board[y][x] = 0;
            }
            cout << top2 << '\n';
            break;
        }
        case 3: // north
        {
            y -= 1;
            if (x >= width || x < 0 || y >= height || y < 0)
            {
                y += 1;
                break;
            }
            dice_rolling(3);
            if (board[y][x] == 0)
                board[y][x] = down2;
            else
            {
                down2 = board[y][x];
                board[y][x] = 0;
            }
            cout << top2 << '\n';
            break;
        }
        case 4: // south
        {
            y += 1;
            if (x >= width || x < 0 || y >= height || y < 0)
            {
                y -= 1;
                break;
            }
            dice_rolling(4);
            if (board[y][x] == 0)
                board[y][x] = down2;
            else
            {
                down2 = board[y][x];
                board[y][x] = 0;
            }
            cout << top2 << '\n';
            break;
        }
        }
        top1 = top2;
        north1 = north2;
        down1 = down2;
        south1 = south2;
        left1 = left2;
        right1 = right2;
        command_num--;
    }
    return 0;
}