#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

extern bool swap(int dir);

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

vector<string> split(string input, char delimiter)
{
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
		answer.push_back(temp);

	return answer;
}

string searchBlockPath(int board[5][5], int destx, int desty, int blockColor)
{
	// 7 is wall
	// get all block of the blockColor
	vector<pair<int, int>> colorBlockPositions;
	bool firstTimeFind = false;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == blockColor && i == desty && j == destx)
				return "";
			if (board[i][j] == blockColor)
				colorBlockPositions.push_back(make_pair(i, j));
		}
	
	// find the route from colorBlock
	int optimal_length = 25;
	string optimal_route;
	for (int l = 0; l < colorBlockPositions.size(); l++)
	{
		queue<pair<string, string>> q;
		string position = to_string(colorBlockPositions[l].first) + "_" + to_string(colorBlockPositions[l].second);
		vector<string> tempPositions;
		q.push(make_pair(position, position));
		int tempBoard[5][5];
		copy(&board[0][0], &board[0][0] + 25, &tempBoard[0][0]);
		int visited[5][5] = { 0 };
		visited[colorBlockPositions[l].first][colorBlockPositions[l].second] = 1;
		while (!(q.empty()))
		{
			string currentPosition = q.front().first;
			string route = q.front().second;
			q.pop();
			tempPositions = split(currentPosition, '_');
			int y = stoi(tempPositions[0]);
			int x = stoi(tempPositions[1]);
			tempPositions.clear();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx > 5 || ny < 0 || ny > 5)
					continue;
				if (tempBoard[ny][nx] == 7)
					continue;
				if (visited[ny][nx] == 1)
					continue;
				string nextPosition = to_string(ny) + "_" + to_string(nx);
				string nextRoute = route + "_" + nextPosition;
				if (nx == destx && ny == desty)
				{
					tempPositions = split(nextRoute, '_');
					int currentRouteLength = tempPositions.size() / 2;
					tempPositions.clear();
					if (currentRouteLength < optimal_length)
					{
						optimal_length = currentRouteLength;
						optimal_route = nextRoute;
						
					}
					while (!q.empty()) q.pop();
					break;
				}
				else
					q.push(make_pair(nextPosition, nextRoute));
			}
		}
		
	}
	return optimal_route;
}

int blank_y = 4;
int blank_x = 4;

string blankBlockRoute(int board[5][5], int destx, int desty, int block_x, int block_y)
{
	// find the route from colorBlock
	int optimal_length = 25;
	string optimal_route;

	queue<pair<string, string>> q;
	string position = to_string(blank_y) + "_" + to_string(blank_x);
	vector<string> tempPositions;
	q.push(make_pair(position, position));
	int tempBoard[5][5];
	copy(&board[0][0], &board[0][0] + 25, &tempBoard[0][0]);
	int visited[5][5] = { 0 };
	visited[blank_y][blank_x] = 1;
	while (!(q.empty()))
	{
		string currentPosition = q.front().first;
		string route = q.front().second;
		q.pop();
		tempPositions = split(currentPosition, '_');
		int y = stoi(tempPositions[0]);
		int x = stoi(tempPositions[1]);
		tempPositions.clear();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
				continue;
			if (tempBoard[ny][nx] == 7)
				continue;
			if (visited[ny][nx] == 1)
				continue;
			if (nx == block_x && ny == block_y)
				continue;
			string nextPosition = to_string(ny) + "_" + to_string(nx);
			string nextRoute = route + "_" + nextPosition;
			if (nx == destx && ny == desty)
			{
				tempPositions = split(nextRoute, '_');
				int currentRouteLength = tempPositions.size() / 2;
				tempPositions.clear();
				if (currentRouteLength < optimal_length)
				{
					optimal_length = currentRouteLength;
					optimal_route = nextRoute;
				}
				while (!q.empty()) q.pop();
				break;
			}
			else
			{
				q.push(make_pair(nextPosition, nextRoute));
				visited[ny][nx] = 1;
			}
		}
	}
		
	return optimal_route;
}

void boardSwap(int board[5][5], int x, int y, int dx, int dy)
{
	int temp = board[dy][dx];
	board[dy][dx] = board[y][x];
	board[y][x] = temp;
}

int previous_num;

void moveBlock(string optimalRoute, int board[5][5])
{
	// 실제로 블록을 옮기는 부분
	vector<string>route = split(optimalRoute, '_');
	for (int i = 0; i <= route.size() - 4; i = i + 2)
	{
		int y = stoi(route[i]);
		int x = stoi(route[i + 1]);
		int dy = stoi(route[i + 2]);
		int dx = stoi(route[i + 3]);
		// 여기에 blank를 위치시키는 부분이 들어가야 한다.
		string blankBlockOptimalRoute = blankBlockRoute(board, dx, dy, x, y);
		vector<string> blankRoute = split(blankBlockOptimalRoute, '_');
		if(!blankRoute.empty())
			for (int j = 0; j <= blankRoute.size() - 4; j = j + 2)
			{
				int temp_y = stoi(blankRoute[j]);
				int temp_x = stoi(blankRoute[j + 1]);
				int temp_dy = stoi(blankRoute[j + 2]);
				int temp_dx = stoi(blankRoute[j + 3]);
				if (temp_dx - temp_x == 1)
				{
					swap(RIGHT);
					boardSwap(board, temp_x, temp_y, temp_dx, temp_dy);
				}
				else if (temp_dx - temp_x == -1)
				{
					swap(LEFT);
					boardSwap(board, temp_x, temp_y, temp_dx, temp_dy);
				}
				else if (temp_dy - temp_y == -1)
				{
					swap(UP);
					boardSwap(board, temp_x, temp_y, temp_dx, temp_dy);
				}
				else if (temp_dy - temp_y == 1)
				{
					swap(DOWN);
					boardSwap(board, temp_x, temp_y, temp_dx, temp_dy);
				}
			}
		if (dx - x == 1)
		{
			swap(LEFT);
			boardSwap(board, x, y, dx, dy);
		}
		else if (dx - x == -1)
		{
			swap(RIGHT);
			boardSwap(board, x, y, dx, dy);
		}
		else if (dy - y == -1)
		{
			swap(DOWN);
			boardSwap(board, x, y, dx, dy);
		}
		else if (dy - y == 1)
		{
			swap(UP);
			boardSwap(board, x, y, dx, dy);
		}
		blank_y = y;
		blank_x = x;
		board[dy][dx] = 7;
	}
}


void solve(int board[5][5], int pattern[3][3], int callCntLimit) {
	// 원하는 블록과 목적지를 매칭해주는 부분
	// 여기서 블록 이동에 따른 board의 갱신도 해줘야 한다.
	for(int i=0; i<5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == 0)
			{
				blank_y = i;
				blank_x = j;
				break;
			}
		}
	for(int i=0; i<3; i++)
		for (int j = 0; j < 3; j++)
		{
			string optimalRoute = searchBlockPath(board, j + 1, i + 1, pattern[i][j]);
			if (optimalRoute == "")
				board[i + 1][j + 1] = 7;
			else
				moveBlock(optimalRoute, board);
		}

}