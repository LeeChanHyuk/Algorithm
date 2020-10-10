#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int n, m;

int arr[10];
bool isused[10];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!isused[i]) // i번째가 사용되지 않았다면
            {
                arr[k] = i;
                isused[i] = 1;
                func(k + 1);
                isused[i] = 0; // 사용한 후에는 반납해야, 이번 단계를 전부 돌고나서 다시 i번째 수를 arr 내에 넣을 수 있다.
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
    return 0;
}