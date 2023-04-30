#include <iostream>

using namespace std;

int arr[101] = {0};
int result[101] = {0};
long long maximum_val = 0;

void back_tracking(int k, int unit, int dalant)
{
    if (k == unit)
    {
        long long mul = 1;
        int sum = 0;
        for(int i=0; i<k; i++)
        {
            mul *= result[i];
            sum += result[i];
        }
        if(sum == dalant && mul > maximum_val)
            maximum_val = mul;
    }
    else
    {
        for(int i=0; i<dalant; i++)
        {
            result[k] = arr[i];
            back_tracking(k+1, unit, dalant);
        }
    }
}


int main(void)
{
    int test_case;
    cin >> test_case;
    for(int i=1; i<101; i++)
        arr[i] = i;

    for(int cases=1; cases <= test_case; cases++)
    {
        maximum_val = 0;
        int dalant, unit;
        cin >> dalant >> unit;
        back_tracking(0, unit, dalant);
        cout << "#" << cases << ' ' << maximum_val << '\n';
    }
    return 0;
}