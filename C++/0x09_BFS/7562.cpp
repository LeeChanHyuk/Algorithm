#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
#define X first
#define Y second
using namespace std;
int board[302][302];
int via[302][302];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int command_num = 0;
	int width = 0;
	int height = 0;
	cin >> command_num;
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

	int done = 0;
	for (int i = 0; i < command_num; i++)
	{
		queue<pair<int, int>> for_via_queue;
		int x1, y1;
		int x2, y2;
		cin >> width >> y1 >> x1 >> y2 >> x2;
		via[y1][x1] = 1;
		if (x1 == x2 && y1 == y2)
		{
			cout << 0<<'\n';
			memset(via, 0, sizeof(via));
			continue;
		}
		for_via_queue.push({y1, x1});
		while (!for_via_queue.empty())
		{
			int x = for_via_queue.front().second;
			int y = for_via_queue.front().first;
			for_via_queue.pop();

			for (int i = 0; i < 8; i++)
			{
				int qx = x + dx[i];
				int qy = y + dy[i];
				if (qx >= width || qy >= width || qx < 0 || qy < 0)
					continue;
				if (via[qy][qx] >= 1)
					continue;
				via[qy][qx] = via[y][x] + 1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
				for_via_queue.push({qy, qx});
				if (qx == x2 && qy == y2)
				{
					cout << via[y][x] << '\n';
					done = 1;
					break;
				}
			}
			if (done)
			{
				done = 0;
				break;
			}
		}
		memset(via, 0, sizeof(via));
	}
	return 0;
}