#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

char stars[2000][2000];

int pow(int num, int num2)
{
    if (num2 == 0)
        return 1;
    else
    {
        return num * pow(num, num2 - 1);
    }
}

void draw_star(int num, pair<int, int> top_position)
{
    int width = 0;
    if (num > 1)
        width = pow(2, num - 1); // 작은 삼각형 한변의 길이
    if (num == 0)
        stars[0][0] = '*';
    else if (num == 1)
    {
        stars[0][0] = '*';
        stars[0][1] = '*';
        stars[1][0] = '*';
    }
    else if (num == 2)
    {
        stars[top_position.first][top_position.second] = '*';
        stars[top_position.first][top_position.second + 1] = '*';
        stars[top_position.first][top_position.second + 2] = '*';
        stars[top_position.first][top_position.second + 3] = '*';
        stars[top_position.first + 1][top_position.second] = '*';
        stars[top_position.first + 1][top_position.second + 2] = '*';
        stars[top_position.first + 2][top_position.second] = '*';
        stars[top_position.first + 2][top_position.second + 1] = '*';
        stars[top_position.first + 3][top_position.second] = '*';
    }
    else
    {
        draw_star(num - 1, {top_position.first, top_position.second});
        draw_star(num - 1, {top_position.first + width, top_position.second});
        draw_star(num - 1, {top_position.first, top_position.second + width});
    }
}

int main(void)
{
    // 출력 시 각 줄의 별까지만 출력해야한다!
    int num = 0;
    cin >> num;
    draw_star(num, {0, 0});
    int big_width = pow(2, num); // 전체 삼각형의 width
    for (int i = 0; i < big_width; i++)
    {
        for (int j = 0; j < big_width - i; j++)
        {
            if (stars[i][j] == '*')
                cout << stars[i][j];
            else
            {
                cout << ' ';
            }
        }
        if (i != big_width - 1)
            cout << '\n';
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}