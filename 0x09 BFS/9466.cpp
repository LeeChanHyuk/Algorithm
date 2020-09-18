#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

char stds[100002]; // 우선 전부 0으로 초기화 된 상태.
char choosen[100002]; // 우선 전부 0으로 초기화 된 상태.
int first_num = 0;

int dfs(int num) // 학생 번호를 인자로 받고
{
	int next_num = stds[num];
	if (choosen[num] == 1) // 찾아간 학생이 이미 짝이 있었을 경우.
		return 0;
	if (next_num == first_num) // 제대로 루프가 형성되었을 경우.
	{
		choosen[num] = 1;
		return 1;
	}
	if (next_num == num) // 찾아간 학생이 자기자신이랑 한다고 할 경우.
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
		// 이러면 여기까진 일단 학생들이 짝짓고 싶은 상대를 다 받은 상태~

		for (int i = 1; i <= num; i++)
		{
			if (choosen[i] == 1)
				continue;
			first_num = i;
			int boolean = dfs(i);
			// 이게 1이면 전부 1로해야하는거고, 0이면 전부 0으로 해야하는 거다.
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