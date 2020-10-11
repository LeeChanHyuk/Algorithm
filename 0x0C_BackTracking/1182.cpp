#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int arr[30];    // 0으로 초기화 되어 있음.
int isused[30]; // false로 초기화 되어 있음.
int s;
int n;
int res = 0;
int cnt = 0;
int cnt2 = 0;
int i_1 = 0;

void backtracking()
{
    if (res == s && cnt2 > 0) // baseline
        cnt++;
    for (int i = i_1; i < n; i++)
    {
        if (isused[i] == 0)
        {
            isused[i] = 1;
            res += arr[i];
            i_1 = i + 1;
            cnt2 += 1;
            backtracking();
            isused[i] = 0;
            res -= arr[i];
            cnt2 -= 1;
        }
    }
    i_1 = 0;
}

int main(void)
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    backtracking();
    cout << cnt;
    return 0;
}