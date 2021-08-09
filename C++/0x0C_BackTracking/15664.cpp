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
int arr[10];  // 입력 받은 배열들
int arr2[10]; // 해당 정답 배열
int arr3[10][10];
vector<vector<int>> arr4; // 정답 배열을 모아둔 벡터
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
                    pass++;
                }
            }
            if (pass == digits)
                break;
            pass = 0;
        }
        if (pass != digits)
        {
            vector<int> a;
            for (int i = 0; i < m; i++)
            {
                a.push_back(arr2[i]);
                cout << arr2[i] << ' ';
            }
            cout << '\n';
            if (arr4.size() > 0)
                if (arr4[arr4.size() - 1][0] < a[0])
                    arr4.clear();
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
            if (digits > 0)
                if (arr2[digits - 1] > arr[i])
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
