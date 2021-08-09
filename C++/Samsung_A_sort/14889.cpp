#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int board[20][20];
int teamA[10];
int teamB[10];
int diff = 30000;
int isused[20];
int cnt = 0;

void backtracking()
{
    if (cnt == n / 2)
    {
        int num = 0;
        for (int i = 0; i < n; i++)
            if (isused[i] == 0)
            {
                teamB[num] = i;
                num++;
            }
        int teamA_score = 0;
        int teamB_score = 0;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
                teamA_score += board[teamA[i]][teamA[j]];

        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
                teamB_score += board[teamB[i]][teamB[j]];
        if (abs(teamA_score - teamB_score) < diff)
            diff = abs(teamA_score - teamB_score);
        return;
    }
    for (int i = cnt; i < n; i++)
    {
        if (isused[i] == 0)
        {
            if (cnt > 0 && i < teamA[cnt - 1])
                continue;
            isused[i] = 1;
            if (cnt < n / 2) // teamA
            {
                teamA[cnt] = i;
                cnt++;
            }
            backtracking();
            isused[i] = 0;
            cnt--;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // S 받기.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    backtracking();
    cout << diff;
    return 0;
}