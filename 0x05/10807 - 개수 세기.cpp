#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
// list�� �Ȱ��� stack<int> a;�� �����ϰ�
// ����� push, pop, top, empty, size���� �ִ�.

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[201] = { 0 };
	int command_num = 0;
	cin >> command_num;
	while (command_num--)
	{
		int num;
		cin >> num;
		arr[num+100]++;
	}
	int num;
	cin >> num;
	cout << arr[num + 100];
	return 0;
}