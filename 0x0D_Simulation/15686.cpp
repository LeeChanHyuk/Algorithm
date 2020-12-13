#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int N, M, homes, chicken_house;
int board[50][50];
int home_x[100];
int home_y[100];
int chicken_x[13];
int chichen_y[13];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    homes = -1;
    chicken_house = -1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                homes++;
                home_y[homes] = i;
                home_x[homes] = j;
            }
            else if (board[i][j] == 2)
            {
                chicken_house++;
                chichen_y[chicken_house] = i;
                chicken_x[chicken_house] = j;
            }
        }
    // 집개수, 치킨집개수, 좌표등은모두파악이끝난상태.
    vector<int> chicken_active(chicken_house + 1, 1);
    fill(chicken_active.begin(), chicken_active.begin() + chicken_house + 1 - M, 0);
    int output = 99999;
    do
    {
        int chicken_distance = 0;
        for (int i = 0; i < homes + 1; i++)
        {
            int temp = 999;
            for (int j = 0; j < chicken_house + 1; j++)
            {
                if (chicken_active[j] == 0)
                    continue;
                temp = min(temp, abs(chicken_x[j] - home_x[i]) + abs(chichen_y[j] - home_y[i]));
            }
            chicken_distance += temp;
        }
        output = min(output, chicken_distance);
    } while (next_permutation(chicken_active.begin(), chicken_active.end()));

    cout << output;
    return 0;
}