#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
// list와 똑같이 stack<int> a;로 선언하고
// 명령은 push, pop, top, empty, size등이 있다.

using namespace std;
std::vector<string> out_buffer;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int command_num = 0;
	stack<int> stack1;
	
	cin >> command_num;
	int index = 1; // 현재 내가 이 수를 받을 차례
	while (command_num--)
	{
		int num = 0;
		cin >> num;
		if (!stack1.empty())
		{
			if (stack1.top() == num)
			{
				out_buffer.push_back("-\n");
				stack1.pop();
			}
			else if (stack1.top() < num && num < index)
			{
				out_buffer.push_back("NO");
				break;
			}
			else if (num >= index)
			{
				for (int i = index; i <= num; i++)
				{
					stack1.push(i);
					out_buffer.push_back("+\n");
					index++;
				}
				out_buffer.push_back("-\n");
				stack1.pop();
			}
			else // num<top
			{
				out_buffer.push_back("NO");
				break;
			}
		}
		else
		{
			if (index <= num)
			{
				for (int i = index; i <= num; i++)
				{
					stack1.push(i);
					out_buffer.push_back("+\n");
					index++;
				}
				out_buffer.push_back("-\n");
				stack1.pop();
			}
			else
				out_buffer.push_back("NO");
		}

	}
	for (int i = 0; i < out_buffer.size(); i++)
	{
		if (out_buffer[i] == "NO")
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < out_buffer.size(); i++)
	{
		cout << out_buffer[i];
	}
	return 0;

}