#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string board[1000];

bool search(int row, int col, int small_width, int area_num)
{
    bool flag = true;
    char first_num = board[row][col];
    for (int i = row; i < row + small_width; i++)
    {
        for (int j = col; j < col + small_width; j++)
        {
            if (board[i][j] != first_num)
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
            break;
        if (i == row + small_width - 1) // 마지막까지 같은게 나오면
        {
            cout << first_num;
            return true;
        }
    }
    return false;
}

void divide_and_conquer(int width, pair<int, int> left_top_position)
{
    int small_width = width / 2;
    // 나눌 때 마다 읽지않을수는없나?
    cout << '(';
    bool area1 = search(left_top_position.first, left_top_position.second, small_width, 1);
    if (!area1)
    {
        divide_and_conquer(small_width, {left_top_position.first, left_top_position.second});
    }
    bool area2 = search(left_top_position.first, left_top_position.second + small_width, small_width, 2);
    if (!area2)
        divide_and_conquer(small_width, {left_top_position.first, left_top_position.second + small_width});
    bool area3 = search(left_top_position.first + small_width, left_top_position.second, small_width, 3);
    if (!area3)
        divide_and_conquer(small_width, {left_top_position.first + small_width, left_top_position.second});
    bool area4 = search(left_top_position.first + small_width, left_top_position.second + small_width, small_width, 4);
    if (!area4)
    {
        divide_and_conquer(small_width, {left_top_position.first + small_width, left_top_position.second + small_width});
    }
    cout << ')';
    // 여기까지
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num = 0;
    cin >> num;
    bool first = false;
    for (int i = 0; i < num; i++)
        cin >> board[i];
    for (int i = 0; i < num; i++)
        for (int j = 0; i < num; i++)
            if (board[i][j] != board[0][0])
                first = true;
    if (first == false)
    {
        cout << board[0][0];
        return 0;
    }

    if (num == 1)
    {
        cout << board[0][0];
    }
    else if (num == 2)
    {
        if (board[0][0] == '0' && board[0][1] == '0' && board[1][0] == '0' && board[1][1] == '0')
        {
            cout << '0';
        }
        else if (board[0][0] == '1' && board[0][1] == '1' && board[1][0] == '1' && board[1][1] == '1')
        {
            cout << '1';
        }
    }
    else
        divide_and_conquer(num, {0, 0});

    return 0;
}