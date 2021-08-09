#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int original_board[8][8];
int board[8][8];
int original_via[8][8];
int via[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int height, width;
    cin >> height >> width;
    queue<pair<int, int>> for_via_queue;
    vector<pair<int, int>> original_for_via_queue;
    bool escape = false;
    int max = 0;
    int sum = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            cin >> original_board[i][j];
            if (original_board[i][j] == 2)
            {
                original_via[i][j] = 1;
                original_for_via_queue.push_back({i, j});
            }
        }
    int brute_force = height * height * height * width * width * width;
    for (int i = 0; i < brute_force; i++)
    {
        for (int j = 0; j < original_for_via_queue.size(); j++)
            for_via_queue.push(original_for_via_queue[j]);
        escape = false;
        int temp = i;
        for (int j = 0; j < height; j++)
            for (int k = 0; k < width; k++)
            {
                board[j][k] = original_board[j][k];
                via[j][k] = original_via[j][k];
            }
        for (int j = 0; j < 3; j++)
        {
            int dir = temp % (width * height);
            temp /= (width * height);
            int row = dir / width;
            int col = dir % width;
            if (board[row][col] == 0)
                board[row][col] = 1;
            else
            {
                escape = true;
                break;
            }
        }
        if (escape)
            continue;
        while (!for_via_queue.empty())
        {
            int x = for_via_queue.front().second;
            int y = for_via_queue.front().first;
            for_via_queue.pop();
            for (int j = 0; j < 4; j++)
            {
                int qx = x + dx[j];
                int qy = y + dy[j];
                if (qx >= width || qy >= height || qx < 0 || qy < 0)
                    continue;
                if (via[qy][qx] == 1 || board[qy][qx] == 1)
                    continue;
                for_via_queue.push({qy, qx});
                via[qy][qx] = 1;
            }
        }
        for (int j = 0; j < height; j++)
            for (int k = 0; k < width; k++)
                if (board[j][k] == 0 && via[j][k] == 0)
                    sum++;
        if (sum > max)
            max = sum;
        sum = 0;
    }
    cout << max;
    return 0;
}