#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int result[9];
int isused[9];

void back_tracking(int k, int m, int n)
{
    if (k == m)
    {
        for(int i=0; i<k; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if (isused[i] != 1)
            {
                result[k] = arr[i];
                isused[i] = 1;
                back_tracking(k+1, m, n);
                isused[i] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    back_tracking(0, m, n);
    return 0;
}