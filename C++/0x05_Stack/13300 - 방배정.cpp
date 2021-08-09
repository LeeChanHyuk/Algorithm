#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
// list와 똑같이 stack<int> a;로 선언하고
// 명령은 push, pop, top, empty, size등이 있다.

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int command_num = 0;
	cin >> command_num;
	int room_max_num = 0;
	cin >> room_max_num;
	int arr[2][6] = { 0 };
	while (command_num--)
	{
		int sex = 0;
		int grade = 0;
		cin >> sex >> grade;
		arr[sex][grade-1]++;
	}
	int room_number = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			room_number = room_number + (arr[i][j] / room_max_num);
			if (arr[i][j] % room_max_num != 0)
				room_number++;
		}
	}
	cout << room_number;
	return 0;
}