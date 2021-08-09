#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int arr[50];
int isused[50];
int out[6];
int num;

void backtracking(int digits)
{
    if (digits == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << out[i] << ' ';
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            if (isused[i] == 1)
                continue;
            if (digits > 0)
                if (arr[i] < out[digits - 1])
                    continue;
            out[digits] = arr[i];
            isused[i] = 1;
            backtracking(digits + 1);
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        fill(arr, arr + 50, 0);
        cin >> num;
        if (num == 0)
            break;
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        sort(arr, arr + num);
        backtracking(0);
        cout << '\n';
    }
}