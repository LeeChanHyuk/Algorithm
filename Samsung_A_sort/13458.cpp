#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

long long all = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, supervisor_can, sub_supervisor_can;
    cin >> n;
    int *students = new int[n + 100];
    for (int i = 0; i < n; i++)
    {
        cin >> students[i];
    }
    cin >> supervisor_can >> sub_supervisor_can;
    for (int i = 0; i < n; i++)
    {
        if (students[i] <= supervisor_can)
            continue;
        int sub_student = students[i] - supervisor_can;
        int number = sub_student / sub_supervisor_can;
        int rest = sub_student % sub_supervisor_can;
        if (rest > 0)
            all += number + 1;
        else
        {
            all += number;
        }
    }
    cout << all + n;
    return 0;
}