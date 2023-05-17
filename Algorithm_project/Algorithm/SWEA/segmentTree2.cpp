#include <iostream>
#include <vector>

using namespace std;

int arr[100] = { 0 };
vector<int> Tree;

int fillTree(int start, int end, int index)
{
	if (start == end)
		return Tree[index] = arr[start];
	int mid = (start + end) / 2;
	return Tree[index] = fillTree(start, mid, index * 2) + fillTree(mid + 1, end, index * 2 + 1);
}

void makeTree(int N)
{
	int level = 1;
	while (level <= N) level *= 2;
	Tree.resize(level * 2, 0);
	
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	fillTree(1, N, 1);
}

int treeSum(int start, int end, int index, int left, int right)
{
	if (left > end || right < start)
		return 0;
	else if (start >= left && end <= right)
		return Tree[index];
	int mid = (start + end) / 2;
	return treeSum(start, mid, index * 2, left, right) + treeSum(mid + 1, end, index * 2, left, right);
}

void changeValInTree(int start, int end, int point, int index, int diff)
{
	Tree[index] += diff;
	if (point > end || point < start || start == end)
		return;
	int mid = (start + end) / 2;
	changeValInTree(start, mid, point, index * 2, diff);
	changeValInTree(mid + 1, end, point, index * 2 + 1, diff);
}

int main(void)
{
	makeTree(10);
	cout << treeSum(1, 10, 1, 1, 5) << '\n';
	changeValInTree(1, 10, 3, 1, 2);
	cout << treeSum(1, 10, 1, 1, 5) << '\n';
	return 0;
}