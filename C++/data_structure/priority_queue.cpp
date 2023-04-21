#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct compares{
bool operator()(pair<int, int>&a, pair<int, int>&b)
{
    if (a.first == b.first)
        return a.second<b.second;
    else
        return a.first<b.first;
}
};

struct compare{
bool operator()(pair<int, int>&a, pair<int, int>&b) {
              if (a.first == b.first) {
                  return a.second < b.second;
              }
              else {
                  return a.first < b.first;
              }
          }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compares> pq;

int main(void)
{
    pq.push({1, 9});
    pq.push({1, 3});
    pq.push({1, 5});
    while (!pq.empty())
    {
        cout << pq.top().second << '\n';
        pq.pop();
    }
    return 0;
}