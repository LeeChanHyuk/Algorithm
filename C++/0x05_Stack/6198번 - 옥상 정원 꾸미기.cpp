#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
	stack<int> building;
	int N, height;
	long long int cnt = 0;

	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &height);
		while (!building.empty()) {
			if (building.top() <= height) building.pop();
			else break;
		}

		building.push(height);

		cnt += (long long int)building.size() - 1;
	}

	printf("%lld", cnt);

	return 0;
}

// 반성하자..