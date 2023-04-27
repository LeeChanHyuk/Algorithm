#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=n*n; i!=0; i--)
    {
        cin >> num;
        pq.push(num);
        if (pq.size() > n)
            pq.pop();
    }
    cout << pq.top();
    return 0;
}