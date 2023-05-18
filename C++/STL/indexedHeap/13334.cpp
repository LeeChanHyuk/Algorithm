#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct house
{
	int start;
	int end;
};

struct compare_minStartHeap
{
	bool operator() (house& a, house& b)
	{
		if (a.start == b.start)
			return a.end < b.end;
		return a.start < b.start;
	}
};

struct compare_minEndHeap
{
	bool operator() (house& a, house& b)
	{
		return a.end < b.end;
	}
};

priority_queue<house, vector<house>, compare_minStartHeap> men;
priority_queue<house, vector<house>, compare_minEndHeap> waiting_men;

int check(int length)
{
	int result = 0;
	while (!men.empty())
	{
		house man = men.top();
		men.pop();

		int start_line = man.start;
		int end_line = man.start + length;

		waiting_men.push(man);
		while (!waiting_men.empty())
		{
			if (waiting_men.top().end > end_line)
				waiting_men.pop();
			else
				break;
		}
		if (waiting_men.size() > result)
			result = waiting_men.size();
	}
	return result;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, start, end, length;
	cin >> n;
	house temp;
	for (register int i = 0; i < n; i++)
	{
		cin >> start >> end;
		if (start > end)
			temp = { end, start };
		else
			temp = { start, end };
		men.push(temp);
	}
	cin >> length;
	int result = check(length);
	cout << result;
	
	return 0;
}