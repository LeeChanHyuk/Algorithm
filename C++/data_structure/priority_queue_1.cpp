#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct compare
{
    bool operator()(pair<string, int>& a, pair<string, int>& b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        else
            return a.second < b.second;
    }
};

int main(void)
{
    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
    pq.push(make_pair("string example", 1));
    pq.push(make_pair("string example", 2));
    pq.push(make_pair("string example", 3));
    cout << pq.top().second;
    pq.pop();
    cout << pq.top().second;
    return 0;
}