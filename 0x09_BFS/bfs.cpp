#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#pragma warning (disable : 4996)
#define X first
#define Y second
using namespace std;
int board[102][102];
int via[102][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int command_num = 0;
	int width = 0;
	int height = 0;
	cin >> height >> width >> command_num;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> for_via_queue;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (via[i][j] == 1)
				continue;
			via[i][j] = 1;
			for_via_queue.push({ i,j });
			while (!for_via_queue.empty())
			{
				int x = for_via_queue.front().second;
				int y = for_via_queue.front().first;
				for_via_queue.pop();

				for (int i = 0; i < 4; i++)
				{
					int qx = x + dx[i];
					int qy = y + dy[i];
					if (qy >= height || qx >= width || qx < 0 || qy < 0)
						continue;
					if (via[qy][qx] == 1)
						continue;
					for_via_queue.push({ qy, qx });
					via[qy][qx] = 1;
				}
			}
		}
	}

    return 0;
}