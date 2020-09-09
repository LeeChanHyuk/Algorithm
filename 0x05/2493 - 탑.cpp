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
	int command_num = 0;
	scanf("%d", &command_num);
	stack<pair<int,int>> stack1;
	int did = 0; 
	for (int i = 1; i <= command_num; i++)
	{
		int num = 0;
		scanf("%d", &num);
		while (!stack1.empty() && stack1.top().second < num)
		{
			stack1.pop();
		}
		if (stack1.empty())
			printf("0 ");
		else
			printf("%d ", stack1.top().first);
		stack1.push(make_pair(i, num));
	}
	return 0;
}