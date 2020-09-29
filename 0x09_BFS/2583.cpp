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

// 백준 2583번 영역 구하기
// C++
// 20200922
// BFS 문제.
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
	for (int i = 0; i < command_num; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				via[k][j] = 1;
			}
		}
	}
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> for_via_queue;
	vector<int> area;
	int area_num = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (via[j][i] == 1)
				continue;
			via[j][i] = 1;
			for_via_queue.push({ i,j });
			int max = 1;
			area_num++;
			while (!for_via_queue.empty())
			{
				int x = for_via_queue.front().X;
				int y = for_via_queue.front().Y;
				for_via_queue.pop();

				for (int i = 0; i < 4; i++)
				{
					int qx = x + dx[i];
					int qy = y + dy[i];
					if (qy >= height || qx >= width || qx < 0 || qy < 0)
						continue;
					if (via[qy][qx] == 1)
						continue;
					via[qy][qx] = 1; // 여기 넣지 않으면 여러번 중복되서 추가될 수도 있다.
					max++;
					for_via_queue.push({ qx, qy });
				}
			}
			area.push_back(max);
			max=0;
		}
	}
	cout << area_num;
	cout << '\n';
	sort(area.begin(), area.end());
	int size = area.size();
	for (int i = 0; i < size; i++)
	{
		cout << area[i]<<' ';
	}

    return 0;
}