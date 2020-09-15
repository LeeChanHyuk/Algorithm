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
	int command_num = 0;
	cin >> command_num;
	while (command_num--)
	{
		list<int> list1;
		list<int>::iterator pivot = list1.begin(); // pivot�� �׻� �ش��ϴ� ���� ���ʿ� ��ġ�Ѵ�. ���ڸ� ���� ���� ���� ���� �����ʿ� �ִ� ���ڸ� �ְ� �����.
		// pivot = ���ε� ��ġ ���� ��쿡�� ���� �� ��ġ ������ ����Ű�� �ȴ�.
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			// ��ɾ�� < > -
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
			{ // erase�� �����ʿ� �ִ� �ָ� ����°Ŵϱ� ����� ������ pivot�� ������ ���� �״�δ�.
				if (pivot != list1.begin())
				{
					pivot--;
					pivot = list1.erase(pivot);
				}
			}
			else // insert
			{ // insert�� �����ʿ� ���� �ִ°Ŵϱ� pivot�� ���������� �ڵ����� �̵��Ѵ�.
				list1.insert(pivot, str[i]);
			}

		}
		for (auto c : list1)
			cout << char(c);
		cout << '\n';
	}
	return 0;
}