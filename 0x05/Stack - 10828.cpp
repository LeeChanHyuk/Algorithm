#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
// list�� �Ȱ��� stack<int> a;�� �����ϰ�
// ����� push, pop, top, empty, size���� �ִ�.

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
		arr[*index] = -1; // ���� ��� ��. �ֳ��ϸ� push�� �� �ڿ������� ����� �� ���̱� ������.
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
	int arr[20000] = { -1 }; // 100¥�� ������ �����.
	int index = -1; // ���� ���� ������ �ִ� ���� ��ġ // ���� ������ 0���� �� ���̴�.
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