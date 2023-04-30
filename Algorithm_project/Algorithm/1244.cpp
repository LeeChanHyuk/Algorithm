#include <iostream>
#include <set>
#include <queue>

using namespace std;


set<pair<int, int>> board_container;
int biggest_result = 0;
int current_board[6] = { 0 };
int temp_board[6] = { 0 };
int sequred_number[6] = { 1, 10, 100, 1000, 10000, 100000 };

void swap(int i, int j)
{
	int temp = current_board[i];
	current_board[i] = current_board[j];
	current_board[j] = temp;
}

bool turn_back = false;

void back_tracking(int k, int exchange_num, int total_board_num_count)
{
	if (k == exchange_num)
	{
		int total_num = 0;
		for (int i = 0; i < total_board_num_count; i++)
			total_num += (current_board[i] * sequred_number[total_board_num_count-1-i]);

		if (total_num > biggest_result)
			biggest_result = total_num;
	}
	else
	{
		for(int i=0; i<total_board_num_count; i++)
			for (int j = i + 1; j < total_board_num_count; j++)
			{
				swap(i, j);
				int total_num = 0;
				for (int i = 0; i < total_board_num_count; i++)
					total_num += (current_board[i] * sequred_number[total_board_num_count-1-i]);
				auto iter = board_container.find(make_pair(total_num, k + 1));
				if (iter == board_container.end())
				{
					board_container.insert(make_pair(total_num, k + 1));
					back_tracking(k + 1, exchange_num, total_board_num_count);
				}
				swap(j, i);
			}
	}
}

int count(int num)
{
	int num_count = 0;
	while (num != 0)
	{
		int res = num % 10;
		temp_board[num_count] = res;
		num /= 10;
		num_count += 1;
	}
	for (int i = 0; i < num_count; i++)
		current_board[num_count - 1 - i] = temp_board[i];
	return num_count;
}

int main(void)
{
	int test_case;
	cin >> test_case;
	for (int cases = 1; cases <= test_case; cases++)
	{
		board_container.clear();
		biggest_result = 0;
		int num, exchange_num;
		cin >> num >> exchange_num;
		int number_count = count(num);
		back_tracking(0, exchange_num, number_count);
		cout << "#" << cases << ' ' << biggest_result << '\n';
	}
	return 0;
}