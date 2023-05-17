#include <iostream>

using namespace std;

long long treeVal[4000002] = { 0 };
long long arr[1000001];
int nodeMaxVal = 0;

long long fillTree(long long start, long long end, long long index)
{
	if (start == end)
	{
		if (index > nodeMaxVal)
			nodeMaxVal = index;
		return treeVal[index] = arr[start];
	}
	long long mid = (start + end) / 2;
	return treeVal[index] = fillTree(start, mid, index * 2) + fillTree(mid + 1, end, index * 2 + 1);
}

void visualizeTree()
{
	int index = 1;
	int jump = 1;
	while (index <= nodeMaxVal)
	{
		if (index == jump)
		{
			cout << '\n';
			jump *= 2;
		}
		cout << treeVal[index] << ' ';
		index += 1;
	}
}

long long treeSum(long long start, long long end, long long index, long long left, long long right)
{
	if (right < start || left > end)
		return 0;
	else if (start >= left && end <= right)
		return treeVal[index];
	long long mid = (start + end) / 2;
	return treeSum(start, mid, index * 2, left, right) + treeSum(mid + 1, end, index * 2 + 1, left, right);
}

void treeValChange(long long start, long long end, long long point, long long addVal, long long index)
{
	treeVal[index] += addVal;
	if (start == end)
		return;
	long long mid = (start + end) / 2;
	if (point >= start && point <= mid)
		treeValChange(start, mid, point, addVal, index * 2);
	else if (point >= mid + 1 && point <= end)
		treeValChange(mid + 1, end, point, addVal, index * 2 + 1);
}

void makeTree(int leafNodeNum)
{
	fillTree(1, leafNodeNum, 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	int n, m, k;
	long long a, b, c;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	makeTree(n);
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			treeValChange(1, n, b, c - arr[b], 1);
			arr[b] = c;
		}
		else if (a == 2)
			cout << treeSum(1, n, 1, b, c) << '\n';
	}
	return 0;
}