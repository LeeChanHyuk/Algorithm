#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>

using namespace std;

int N;
int board[20][20];
int temp_board[20][20];
int maxs = 0;

// brute force로 풀어보자.
// 모든 경우의 수는 4^5승
// 00000 00001 00002 00003 이런식으로 가야할 듯

// 0 - 오른쪽 / 1 - 아래쪽 / 2 - 왼쪽 / 3 - 위쪽
// 같으면 우선 더하고
// 더해진 곳엔 더한 값을, 더한 곳엔 0을 둔다.
void tilting(int direction)
{
    if (direction == 0) // right direction
    {
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = N - 1; j >= 0; j--)
            {
                if (temp_board[i][j] != 0)
                    for (int k = N - 1; k > j; k--)
                        if (temp_board[i][k] == 0)
                        {
                            temp_board[i][k] = temp_board[i][j];
                            temp_board[i][j] = 0;
                            break;
                        }
            }
        for (int i = 0; i < N; i++)
            for (int j = N - 1; j > 0; j--)
            {
                int sum;
                if (temp_board[i][j] == temp_board[i][j - 1]) // 더하는 과정
                {
                    sum = temp_board[i][j] + temp_board[i][j - 1];
                    temp_board[i][j] = sum;
                    temp_board[i][j - 1] = 0;
                }
            }
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = N - 1; j >= 0; j--)
            {
                if (temp_board[i][j] != 0)
                    for (int k = N - 1; k > j; k--)
                        if (temp_board[i][k] == 0)
                        {
                            temp_board[i][k] = temp_board[i][j];
                            temp_board[i][j] = 0;
                            break;
                        }
            }
    }
    else if (direction == 1) // down direction
    {
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = N - 1; j >= 0; j--)
            {
                if (temp_board[j][i] != 0)
                    for (int k = N - 1; k > j; k--)
                        if (temp_board[k][i] == 0)
                        {
                            temp_board[k][i] = temp_board[j][i];
                            temp_board[j][i] = 0;
                            break;
                        }
            }
        for (int i = 0; i < N; i++)
            for (int j = N - 1; j > 0; j--)
            {
                int sum;
                if (temp_board[j][i] == temp_board[j - 1][i]) // 더하는 과정
                {
                    sum = temp_board[j][i] + temp_board[j - 1][i];
                    temp_board[j][i] = sum;
                    temp_board[j - 1][i] = 0;
                }
            }
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = N - 1; j >= 0; j--)
            {
                if (temp_board[j][i] != 0)
                    for (int k = N - 1; k > j; k--)
                        if (temp_board[k][i] == 0)
                        {
                            temp_board[k][i] = temp_board[j][i];
                            temp_board[j][i] = 0;
                            break;
                        }
            }
    }
    else if (direction == 2) // left direction
    {
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = 0; j < N; j++)
            {
                if (temp_board[i][j] != 0)
                    for (int k = 0; k < j; k++)
                        if (temp_board[i][k] == 0)
                        {
                            temp_board[i][k] = temp_board[i][j];
                            temp_board[i][j] = 0;
                            break;
                        }
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - 1; j++)
            {
                int sum;
                if (temp_board[i][j] == temp_board[i][j + 1]) // 더하는 과정
                {
                    sum = temp_board[i][j] + temp_board[i][j + 1];
                    temp_board[i][j] = sum;
                    temp_board[i][j + 1] = 0;
                }
            }
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = 0; j < N; j++)
            {
                if (temp_board[i][j] != 0)
                    for (int k = 0; k < j; k++)
                        if (temp_board[i][k] == 0)
                        {
                            temp_board[i][k] = temp_board[i][j];
                            temp_board[i][j] = 0;
                            break;
                        }
            }
    }
    else // direction == 3 // up direction
    {
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = 0; j < N; j++)
            {
                if (temp_board[j][i] != 0)
                    for (int k = 0; k < j; k++)
                        if (temp_board[k][i] == 0)
                        {
                            temp_board[k][i] = temp_board[j][i];
                            temp_board[j][i] = 0;
                            break;
                        }
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - 1; j++)
            {
                int sum;
                if (temp_board[j][i] == temp_board[j + 1][i]) // 더하는 과정
                {
                    sum = temp_board[j][i] + temp_board[j + 1][i];
                    temp_board[j][i] = sum;
                    temp_board[j + 1][i] = 0;
                }
            }
        for (int i = 0; i < N; i++) // 미는 과정
            for (int j = 0; j < N; j++)
            {
                if (temp_board[j][i] != 0)
                    for (int k = 0; k < j; k++)
                        if (temp_board[k][i] == 0)
                        {
                            temp_board[k][i] = temp_board[j][i];
                            temp_board[j][i] = 0;
                            break;
                        }
            }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int brute_force = 1 << 10; // 2의 10승 == 4의 5승

    for (int i = 0; i < brute_force; i++)
    {
        int temp = i;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                temp_board[j][k] = board[j][k];
        for (int j = 0; j < 10; j++)
        {
            int dir = temp % 4;
            temp = temp / 4;
            // 이러면 dir이 방향을 나타내게 되는거지.
            tilting(dir);
        }
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (temp_board[j][k] > maxs)
                    maxs = temp_board[j][k];
    }
    cout << maxs;

    return 0;
}