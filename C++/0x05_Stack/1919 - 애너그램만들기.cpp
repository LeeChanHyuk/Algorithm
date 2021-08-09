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
	int arr1[26] = { 0 };
	int arr2[26] = { 0 };
	int same = 1;
	int must_delete = 0;
	string word1;
	string word2;
	cin >> word1 >> word2;
	for (int j = 0; j < word1.size(); j++)
	{
		arr1[word1[j] - 97]++;
	}
	for (int j = 0; j < word2.size(); j++)
	{
		arr2[word2[j] - 97]++;
	}
	for (int j = 0; j < 26; j++)
	{
		if (arr1[j] != arr2[j])
		{
			same = 0;
			if (arr1[j] > arr2[j])
				must_delete = must_delete + (arr1[j] - arr2[j]);
			else
				must_delete = must_delete + (arr2[j] - arr1[j]);
		}
	}
	cout << must_delete;
	return 0;
}