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
	while (command_num--)
	{
		list<int> list1;
		list<int>::iterator pivot = list1.begin(); // pivot은 항상 해당하는 숫자 왼쪽에 위치한다. 숫자를 넣을 때든 지울 때든 오른쪽에 있는 숫자를 넣고 지운다.
		// pivot = 새로들어간 위치 같은 경우에는 새로 들어간 위치 왼쪽을 가리키게 된다.
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			// 명령어는 < > -
			if (str[i] == '<')
			{
				if (pivot != list1.begin())
				{
					pivot--;
				}
			}
			else if (str[i] == '>')
			{
				if (pivot != list1.end())
				{
					pivot++;
				}
			}
			else if (str[i] == '-') // erase
			{ // erase는 오른쪽에 있는 애를 지우는거니까 지우고 나서는 pivot의 변동이 없이 그대로다.
				if (pivot != list1.begin())
				{
					pivot--;
					pivot = list1.erase(pivot);
				}
			}
			else // insert
			{ // insert는 오른쪽에 뭐를 넣는거니까 pivot이 오른쪽으로 자동으로 이동한다.
				list1.insert(pivot, str[i]);
			}

		}
		for (auto c : list1)
			cout << char(c);
		cout << '\n';
	}
	return 0;
}