#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int command_num;
void repeat(int num)
{
    if (num == 0)
    {
        for (int i = 0; i < command_num - num; i++)
        {
            cout << "____";
        }
        cout << "\"����Լ��� ������?\"\n";
        for (int i = 0; i < command_num - num; i++)
        {
            cout << "____";
        }
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }
    else
    {
        for (int i = 0; i < command_num - num; i++)
        {
            cout << "____";
        }
        cout << "\"����Լ��� ������?\"\n";
        for (int i = 0; i < command_num - num; i++)
        {
            cout << "____";
        }
        cout << "\""
             << "�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        for (int i = 0; i < command_num - num; i++)
        {
            cout << "____";
        }
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        for (int i = 0; i < command_num - num; i++)
        {
            cout << "____";
        }
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    }
    int a = num - 1;
    if (num != 0)
        repeat(a);
    for (int i = 0; i < command_num - num; i++)
    {
        cout << "____";
    }
    cout << "��� �亯�Ͽ���.\n";
}

int main(void)
{
    cin >> command_num;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    repeat(command_num);
    return 0;
}