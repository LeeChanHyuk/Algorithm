#include <iostream>
#include <cstring>
using namespace std;
 
int n;
int c;
int flag;
int map[100010];
int visit[100010];
 
int DFS(int a, int x)
{
	int cycle = 0;
 
	if (flag == 1 || visit[a] != 0) {
		return 0;
	}
 
	int b = map[a];
	visit[a] = 1;
 
	if (b == x) {
		flag = 1;
		visit[x] = 1;
		return 1;
	}
 
	if (visit[b] == 0) {
		cycle = DFS(b, x);
	}
	
	if (cycle == 1) {
		visit[a] = 1;
		return 1;
	}
	visit[a] = 0;
	return 0;
}
 
int main(int argc, char *argv[])
{
	int testcase;
 
	scanf("%d", &testcase);
 
	while (testcase--) {
		c = 0;
 
		scanf("%d", &n);
 
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
 
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d", &a);
			map[i] = a;
		}
 
		for (int i = 1; i <= n; ++i) {
			if (visit[i] == 1) {
				continue;
			}
 
			flag = 0;
 
			if (DFS(i, i) == 0) {
				visit[i] = -1;
			}
		}
		
		for (int i = 1; i <= n; ++i) {
			if (visit[i] == 1) {
				++c;
			}
		}
 
		printf("%d\n", n - c);
	}
	return 0;
}