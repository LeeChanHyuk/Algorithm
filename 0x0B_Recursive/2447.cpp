#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

char stars[10000][10000];

void print(int num, pair<int, int> start_point)
{
    int width = num / 3;
    pair<int, int> point1 = {start_point.first, start_point.second};
    pair<int, int> point2 = {start_point.first, start_point.second + width};
    pair<int, int> point3 = {start_point.first, start_point.second + width * 2};
    pair<int, int> point4 = {start_point.first + width, start_point.second};
    pair<int, int> point5 = {start_point.first + width, start_point.second + width * 2};
    pair<int, int> point6 = {start_point.first + width * 2, start_point.second};
    pair<int, int> point7 = {start_point.first + width * 2, start_point.second + width};
    pair<int, int> point8 = {start_point.first + width * 2, start_point.second + width * 2};
    pair<int, int> point9 = {start_point.first + width, start_point.second + width};
    if (width == 1)
    {
        stars[point1.first][point1.second] = '*';
        stars[point2.first][point2.second] = '*';
        stars[point3.first][point3.second] = '*';
        stars[point4.first][point4.second] = '*';
        stars[point9.first][point9.second] = ' ';
        stars[point5.first][point5.second] = '*';
        stars[point6.first][point6.second] = '*';
        stars[point7.first][point7.second] = '*';
        stars[point8.first][point8.second] = '*';
        
    }
    else
    {
        //구역 할당. 1,2,3,4,5,6,7,8
        print(width, point1);
        print(width, point2);
        print(width, point3);
        print(width, point4);
        print(width, point5);
        print(width, point6);
        print(width, point7);
        nt(width, point8);
        }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> queue;
    int wid = 0;
    cin >> wid;
    for (int i = 0; i < wid; i++)
    {
        for (int j = 0; j < wid; j++)
            stars[i][j] = ' ';
    }
    print(wid, {0, 0});
    for (int i = 0; i < wid; i++)
    {
        for (int j = 0; j < wid; j++)
            cout << stars[i][j];
        cout << '\n';
    }
    return 0;
}