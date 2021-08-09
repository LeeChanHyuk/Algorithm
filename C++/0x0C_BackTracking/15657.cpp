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
int arr3[10][10];
vector<vector<int>> arr4;
int isused[10];
int pass = 0;

void backtracking(int digits)
{
    if (digits == m)
    {
        for (int i = 0; i < arr4.size(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr4[i][j] == arr2[j])
                {
                    pass = 1;
                    break;
                }
            }
            if (pass)
                break;
        }
        if (pass == 0)
        {
            vector<int> a;
            for (int i = 0; i < m; i++)
            {
                a.push_back(arr2[i]);
                cout << arr2[i] << ' ';
            }
            cout << '\n';
            arr4.push_back(a);
        }
        pass = 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (isused[i] != 0)
                continue;
            isused[i] = 1;
            arr2[digits] = arr[i];
            backtracking(digits + 1);
            isused[i] = 0;
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
