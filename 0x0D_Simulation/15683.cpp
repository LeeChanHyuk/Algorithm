#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int board[8][8];
int n, m;
vector<pair<int, int>> cctvs;

int right(int height, int width)
{
    int right = 0;
    for (int i = width + 1; i < m; i++)
        if (board[height][i] == 0)
            right++;
    return right;
}

int up(int height, int width)
{
    int up = 0;
    for (int i = height - 1; i >= 0; i--)
        if (board[i][width] == 0)
            up++;
    return up;
}
int left(int height, int width)
{
    int left = 0;
    for (int i = width - 1; i >= 0; i++)
        if (board[height][i] == 0)
            left++;
    return left;
}
int down(int height, int width)
{
    int down = 0;
    for (int i = height + 1; i < n; i++)
        if (board[i][width] == 0)
            down++;
    return down;
}

int max_val(int up, int right, int down, int left)
{
    if (up >= right && up >= down && up >= left)
        return up;
    else if (right >= up && right >= down && right >= left)
        return right;
    else if (down >= up && down >= right && down >= left)
        return down;
    else
    {
        return left;
    }
}
int min_val(int up, int right, int down, int left)
{
    if (up <= right && up <= down && up <= left)
        return up;
    else if (right <= up && right <= down && right <= left)
        return right;
    else if (down <= up && down <= right && down <= left)
        return down;
    else
    {
        return left;
    }
}
int direction(int num, int height, int width) // 매개변수는 cctv 인덱스
{
    int up_val = up(height, width);
    int right_val = right(height, width);
    int left_val = left(height, width);
    int down_val = down(height, width);
    int max = max_val(up_val, right_val, down_val, left_val);
    if (num == 1)
    {
        if (max == up_val)
            for (int i = height - 1; i >= 0; i--)
                board[i][width] = 7;
        else if (max == right_val)
            for (int i = width + 1; i < m; i++)
                board[height][i] = 7;
        else if (max == left_val)
            for (int i = width - 1; i >= 0; i++)
                board[height][i] = 7;
        else
            for (int i = height + 1; i < n; i++)
                board[i][width] = 7;
    }
    else if (num == 2) // 양 방향일 경우
    {
        int horizontal = left_val + right_val;
        int vertical = up_val + down_val;
        if (horizontal >= vertical)
        {
            for (int i = width + 1; i < m; i++)
                if (board[height][i] == 0)
                    board[height][i] = 8;
            for (int i = width - 1; i >= 0; i--)
                if (board[height][i] == 0)
                    board[height][i] = 8;
        }
        else
        {

            for (int i = height + 1; i < n; i++)
                if (board[i][width] == 0)
                    board[i][width] = 8;
            for (int i = height - 1; i >= 0; i--)
                if (board[i][width] == 0)
                    board[i][width] = 8;
        }
    }
    else if (num == 3) // 수직방향일경우
    {
        // max값 찾는거를 list 돌면서 찾는거롤 바꾸자. 그러면 3개일 때도 쓸 수 있는 깔끔한 코드가 되겠지.
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            if (a > 0 && a < 6)
                cctvs.push_back({i, j});
            board[i][j] = a;
        }
    } // 입력 배열

    return 0;
}