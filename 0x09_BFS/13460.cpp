#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

char board[10][10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int height, width;
    cin >> height >> width;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cin >> board[i][j];
    int brute_force = 1 << 20;

    return 0;
}