#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long

vector<ll> a;
vector<ll> b;

void moo_game(int number)
{
    int s = 3;
    int mid = 3;
    while (s < number)
    {
        mid++;
        s = 2 * s + mid;
    }
    while (1)
    {
        if (number == 1)
        {
            cout << 'm';
            return;
        }
        else if (number == 2)
        {
            cout << 'o';
            return;
        }
        else if (number == 3)
        {
            cout << 'o';
            return;
        }
        int previous_s = (s - mid) / 2;
        if (number > previous_s && number <= previous_s + mid)
        {
            // in mid
            if (number - previous_s == 1)
            {
                cout << 'm';
                return;
            }
            else
            {
                cout << 'o';
                return;
            }
        }
        else if (number <= previous_s)
        {
            // in previous_s
            s = previous_s;
            mid--;
        }
        else
        {
            // in second previous_s
            number -= (previous_s + mid);
            s = previous_s;
            mid--;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll number = 0;
    cin >> number;
    moo_game(number);

    return 0;
}