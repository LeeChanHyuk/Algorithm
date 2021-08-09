#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int a[8];
int n, m;

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        a[i] = 0;
    for (int i = m; i < n; i++)
        a[i] = 1;
    do
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                cout << i + 1<<' ';
        }
        cout << '\n';
    } while (next_permutation(a, a + n));
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}