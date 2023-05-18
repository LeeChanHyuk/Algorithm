#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct node
{
	int start_day = 0;
	int end_day = 0;
	int money = 0;
};

bool compare (node& a, node& b)
{
	if (a.end_day == b.end_day)
		return a.start_day < b.start_day; // 오름차순 정렬
	return a.end_day < b.end_day; // 오름차순 정렬
}

vector<node> nodes;
int D[501];
int P[501];

int main(void)
{
	int test_case;
	freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	for (int cases = 1; cases <= test_case; cases++)
	{
		nodes.clear();
		memset(D, 0, sizeof(D));
		memset(P, 0, sizeof(P));
		int work_num, day, start_day, end_day, money;
		cin >> work_num >> day;
		node temp_node;
		nodes.push_back(temp_node);
		for (int work = 0; work < work_num; work++)
		{
			cin >> start_day >> end_day >> money;
			temp_node.start_day = start_day;
			temp_node.end_day = end_day;
			temp_node.money = money;
			nodes.push_back(temp_node);
		}
		sort(nodes.begin(), nodes.end(), compare);
		for (int i = 1; i <= work_num; i++)
		{
			D[i] = nodes[i].money;
			for(int j=i-1; j>0; j--)
				if (nodes[j].end_day < nodes[i].start_day)
				{
					P[i] = j;
					break;
				}
			D[i] = max(D[i - 1], D[P[i]] + nodes[i].money);
		}
	cout << "#" << cases << " " << D[work_num] << '\n';
	}
	return 0;
}