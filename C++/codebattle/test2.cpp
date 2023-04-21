#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct compare{
bool operator()(pair<int, int>&a, pair<int, int>&b) {
              if (a.first == b.first) {
                  return a.second > b.second;
              }
              else {
                  return a.first < b.first;
              }
          }
};

priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

int main(void)
{
    int a;
    a = 7/2;
    cout << a;
    return 0;
}