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
		int room_number = 0;
		cin >> room_number;
		int a[7] = { 0 };
		int b[10] = { 0 };
		a[0] = room_number / 1000000;
		a[1] = (room_number % 1000000) / 100000;
		a[2] = (room_number % 100000) / 10000;
		a[3] = (room_number % 10000) / 1000;
		a[4] = (room_number % 1000) / 100;
		a[5] = (room_number % 100) / 10;
		a[6] = (room_number % 10);
		int number = 0;
		for (int i = 0; i < 7; i++)
			if (a[i] != 0)
			{
				number = i;
				break;
			}
		for (int i = number; i < 7; i++)
		{
			if (a[i] == 9)
				a[i] = 6;
			b[a[i]]++;
		}
		if (b[6] % 2 != 0)
			b[6] = (b[6] / 2) + 1;
		else
			b[6] = b[6] / 2;
		int max = 1;
		for (int i = 0; i < 9; i++)
		{
			if (b[i] > max)
				max = b[i];

		}
		if (room_number == 0)
			cout << "1";
		else
			cout << max;
	return 0;
}