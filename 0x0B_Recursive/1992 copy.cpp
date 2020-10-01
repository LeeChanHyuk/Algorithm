#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string board[100];

int divide_and_conquer(int width, pair<int, int> left_top_position)
{
    int small_width = width / 2;
    // 나눌 때 마다 읽지않을수는없나?
    if (small_width == 1)
    {
    }
    else
    {
        bool flag=true;
        for (int i = left_top_position.first; i < left_top_position.first + small_width; i++)
        {
            for (int j = left_top_position.second; j < left_top_position.second + small_width; j++)
            {
                
            }
        }
        int area1 = divide_and_conquer(small_width, {left_top_position.first, left_top_position.second});
        int area2 = divide_and_conquer(small_width, {left_top_position.first, left_top_position.second + small_width});
        int area3 = divide_and_conquer(small_width, {left_top_position.first + small_width, left_top_position.second});
        int area4 = divide_and_conquer(small_width, {left_top_position.first + small_width, left_top_position.second + small_width});
        if (area1 == 1 && area2 == 1 && area3 == 1 && area4 == 1)
            return 1;
        else if (area1 == 0 && area2 == 0 && area3 == 0 && area4 == 0)
            return 0;
        else // 섞여있을 때
        {
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            cin >> board[i][j];

    return 0;
}