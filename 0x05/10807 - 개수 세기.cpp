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