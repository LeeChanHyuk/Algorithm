#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
struct compare
{
    bool operator()(pair<int, int>&a, pair<int, int>&b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first > b.first;
    }

};

priority_queue<int> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq2;

int main(void)
{
    vector<int> vec;
    queue<int> q;
    vec.push_back(1);
    vec.push_back(2);
    q.push(1);
    pq2.push({1,3});
    pq2.push({5,5});
    printf("%d %d", pq2.top().first, pq2.top().second);
    return 0;
}