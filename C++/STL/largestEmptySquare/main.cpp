#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
int board[1001][1001];
int marking[1001][1001];


int main(void)
{
	int test_case;
	freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	for (int cases = 1; cases <= test_case; cases++) {
		int N, temp_num;
		cin >> N;
		memset(board, 0, sizeof(board));
		memset(marking, 0, sizeof(marking));
		for (int i = 0; i < N; i++)
		{
			string temp;
			cin >> temp;
			for (int j = 0; j < temp.size(); j++)
			{
				board[i][j] = int(temp[j]) - '0';
				if (board[i][j] == 0)
					marking[i][j] = 1;
			}
			
		}
		int max_num = 0;
		for(int i=1; i<N; i++)
			for (int j = 1; j < N; j++)
			{
				if (board[i][j] == 0)
				{
					marking[i][j] = min({ marking[i - 1][j], marking[i][j - 1], marking[i - 1][j - 1] }) + 1;
					if (marking[i][j] > max_num)
						max_num = marking[i][j];
				}
			}
		cout << "#" << cases << " " << max_num << '\n';
	}
	return 0;
}