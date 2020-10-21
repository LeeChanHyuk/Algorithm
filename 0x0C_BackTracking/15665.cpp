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
int arr[50];  // 입력 받은 배열들
int arr2[10]; // 해당 정답 배열
int arr3[10][10];
vector<vector<int>> arr4; // 정답 배열을 모아둔 벡터
int isused[10];
int number[10];
int new_n = 0;

void backtracking(int digits)
{
    if (digits == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr2[i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < new_n; i++)
        {
            arr2[digits] = arr[i];
            backtracking(digits + 1);
        }
    }
}

int main(void)
{
    vector<int> zero;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    sort(number, number + n); // 오름차순으로 정렬 완료.
    for (int i = 1; i < n; i++)
    {
        if (number[i] == number[i - 1])
            zero.push_back(i);
    }
    for (int i = 0; i < zero.size(); i++)
        number[zero[i]] = 0;
    int arr_n = 0;
    for (int i = 0; i < n; i++)
    {
        if (number[i] > 0)
        {
            arr[arr_n] = number[i];
            arr_n++;
            new_n++;
        }
    }
    backtracking(0);

    return 0;
}
