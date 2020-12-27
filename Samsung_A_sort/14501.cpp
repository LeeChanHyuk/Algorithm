#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int task[15];
int task_period[15];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> money;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int term, term_money;
        cin >> term >> term_money;
        money.push_back({term, term_money});
    }
    bool can = true;
    int result = 0;
    int sum = 0;
    int brute_force = 1 << n;
    for (int i = 0; i < brute_force; i++)
    {
        int temp = i;
        for (int j = 0; j < n; j++)
        {
            int dir = temp % 2;
            temp /= 2;
            task[j] += dir;
        }
        for (int j = 0; j < n; j++)
        {
            if (task[j] && j + money[j].first <= n)
            {
                sum += money[j].second;
                for (int k = j; k < j + money[j].first; k++)
                {
                    task_period[k]++;
                    if (task_period[k] > 1)
                        can = false;
                }
            }
        }
        if (can)
        {
            if (result < sum)
            {
                result = sum;
            }
        }
        can = true;
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            task[j] = 0;
            task_period[j] = 0;
        }
    }
    cout << result;

    return 0;
}