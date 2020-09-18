#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

char stds[100002]; // �켱 ���� 0���� �ʱ�ȭ �� ����.
char choosen[100002]; // �켱 ���� 0���� �ʱ�ȭ �� ����.
int first_num = 0;

int dfs(int num) // �л� ��ȣ�� ���ڷ� �ް�
{
	int next_num = stds[num];
	if (choosen[num] == 1) // ã�ư� �л��� �̹� ¦�� �־��� ���.
		return 0;
	if (next_num == first_num) // ����� ������ �����Ǿ��� ���.
	{
		choosen[num] = 1;
		return 1;
	}
	if (next_num == num) // ã�ư� �л��� �ڱ��ڽ��̶� �Ѵٰ� �� ���.
		return 0;
	int a = dfs(next_num);
	if (a == 1)
		choosen[num] = 1;
	return a;
}

int main(void)
{
	int test_case = 0;
	cin >> test_case;
	for (int test = 0; test < test_case; test++)
	{
		int num = 0;
		cin >> num;
		int poor = 0;
		for (int i = 1; i <= num; i++)
		{
			int stud = 0;
			cin >> stud;
			stds[i] = stud;
		}
		// �̷��� ������� �ϴ� �л����� ¦���� ���� ��븦 �� ���� ����~

		for (int i = 1; i <= num; i++)
		{
			if (choosen[i] == 1)
				continue;
			first_num = i;
			int boolean = dfs(i);
			// �̰� 1�̸� ���� 1���ؾ��ϴ°Ű�, 0�̸� ���� 0���� �ؾ��ϴ� �Ŵ�.
			if (boolean != 1)
				poor++;
			else
				choosen[i] = 1;
		}
		printf("%d\n", poor);
		memset(stds, 0, sizeof(stds));
		memset(choosen, 0, sizeof(choosen));
	}
	int test = 0;
	scanf("%d", &test);
	return 0;
}