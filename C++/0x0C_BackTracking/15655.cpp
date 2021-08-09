#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int arr2[10];
int isused[10];

void backtracking(int digits)
{
    if (digits == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr2[i] << ' ';
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (digits != 0)
                if (arr[i] <= arr2[digits - 1])
                    continue;
            if (isused[i] == 0)
            {
                isused[i] = 1;
                arr2[digits] = arr[i];
                backtracking(digits + 1);
                isused[i] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n); // 오름차순으로 정렬 완료.
    backtracking(0);

    return 0;
}
