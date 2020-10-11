#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int arr[10];
int isused[10];

int n, m;
int cnt = 0;

void backtracking(int num)
{
    if (num == m + 1 && cnt > 0)
    {
        for (int i = 1; i <= m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i < arr[num - 1])
                continue;
            arr[num] = i;
            cnt += 1;
            backtracking(num + 1);
            cnt -= 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    backtracking(1);
    return 0;
}