#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
// list와 똑같이 stack<int> a;로 선언하고
// 명령은 push, pop, top, empty, size등이 있다.

using namespace std;
int arr[500000] = { 0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int command_num = 0;
	cin >> command_num;
	stack<int> stack1;
	int did = 0; make_pair();
	for (int i = 0; i < command_num; i++)
	{
		did = 0;
		int num = 0;
		cin >> num;
		arr[i] = num;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] >= num)
			{
				printf("%d ",j + 1);
				did = 1;
				break;
			}
		}
		if (did == 0)
			printf("0 ");
	}
	return 0;
}