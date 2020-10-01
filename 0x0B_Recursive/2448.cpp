#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
//줘야 하는건 한 변의 길이와, 좌표. 좌푶는 꼭지점의 좌표를 주자.
char stars[10000][10000];

void draw_star(int num, pair<int, int> pik)
{
    if (num == 3)
    {
        stars[pik.first][pik.second] = '*';
        stars[pik.first + 1][pik.second - 1] = '*';
        stars[pik.first + 1][pik.second + 1] = '*';
        for (int i = 0; i < 5; i++)
            stars[pik.first + 2][pik.second - 2 + i] = '*';
    }
    else
    {
        draw_star(num / 2, {pik.first, pik.second});
        draw_star(num / 2, {pik.first + num / 2, pik.second - num / 2});
        draw_star(num / 2, {pik.first + num / 2, pik.second + num / 2});
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 2 * num - 1; j++)
        {
            stars[i][j] = ' ';
        }
    }
    draw_star(num, {0, num-1});
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 2 * num - 1; j++)
        {
            cout << stars[i][j];
        }
        cout << '\n';
    }
    return 0;
}