#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int board[3000][3000];
int arr[3];

void recursive(int N, pair<int, int> start_point)
{
    int y = start_point.first;
    int x = start_point.second;
    int a = board[y][x];
    bool stop = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[y + i][x + j] != a)
            {
                stop = true;
                break;
            }
        }
        if (stop)
            break;
    }
    if (!stop)
        arr[a + 1] = arr[a + 1] + 1;
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                recursive(N / 3, {start_point.first + i * (N/3), start_point.second + j * (N/3)});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    recursive(N, {0, 0});
    cout << arr[0] << '\n'
         << arr[1] << '\n'
         << arr[2] << '\n';
    return 0;
}