#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
// list와 똑같이 stack<int> a;로 선언하고
// 명령은 push, pop, top, empty, size등이 있다.

using namespace std;

void push(int * arr, int* index, int num)
{
	*index = *index + 1;
	arr[*index] = num;
}

void pop(int* arr, int* index)
{
	if (*index != -1)
	{
		cout << arr[*index] << '\n';
		arr[*index] = -1; // 굳이 없어도 됌. 왜냐하면 push할 때 자연스럽게 덮어씌워 질 것이기 때문에.
		*index = *index - 1;
	}
	else
		cout << "-1\n";
}

void top(int* arr, int index)
{
	if (index != -1)
		cout << arr[index] << '\n';
	else
		cout << "-1\n";
}

void empty(int index)
{
	if (index == -1)
		cout << "1\n";
	else
		cout << "0\n";
}

int size(int index)
{
	return index + 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[20000] = { -1 }; // 100짜리 스택을 만든다.
	int index = -1; // 현재 가장 상위에 있는 원소 위치 // 가장 상위를 0으로 할 것이다.
	int command_num = 0;
	cin >> command_num;
	string command;
	while (command_num--)
	{
		cin >> command;
		if (command == "push")
		{
			int x;
			cin >> x;
			push(arr, &index, x);
		}
		else if (command == "pop")
		{
			pop(arr, &index);
		}
		else if (command == "size")
		{
			cout << size(index) << '\n';
		}
		else if (command == "empty")
		{
			empty(index);
		}
		else
		{
			top(arr, index);
		}
	}


	return 0;
}