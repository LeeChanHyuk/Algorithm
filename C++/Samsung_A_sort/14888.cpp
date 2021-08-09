#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int opera[4];
int arr[11];
int min_result = 2147483647;
int max_result;

// 바꾸는 부분과 연산하는 부분으로 구성.

void operate(int n, vector<int> op)
{
    int start_value = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (op[i] == 0)
            start_value += arr[i + 1];
        else if (op[i] == 1)
            start_value -= arr[i + 1];
        else if (op[i] == 2)
            start_value *= arr[i + 1];
        else // op[i] == 3
        {
            if (arr[i + 1] < 0)
            {
                start_value /= abs(arr[i + 1]);
                start_value *= (-1);
            }
            else
            {
                start_value /= arr[i + 1];
            }
        }
    }
    if (start_value > max_result)
        max_result = start_value;
    if (start_value < min_result)
        min_result = start_value;
}

int main(void)
{
    max_result = (-1) * min_result - 1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> op;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
            op.push_back(i);
    }
    // op에는 연산자 개수만큼 0 1 2 3 이 들어가 있음.
    // op의 오름차순 정렬.
    sort(op.begin(), op.end());
    do
    {
        operate(n, op);
    } while (next_permutation(op.begin(), op.end()));
    cout << max_result << '\n';
    cout << min_result;
    return 0;
}
