#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first > b.first;
	}
};

int main(void)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push(make_pair(1, 2));
	pq.push(make_pair(1, 3));
	while (!pq.empty())
	{
		cout << pq.top().second << '\n';
		pq.pop();
	}
	
	return 0;
}