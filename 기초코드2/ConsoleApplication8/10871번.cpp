#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;



int main()
{
	// ���� N���� �̷���� ���� A�� ���� X�� �־�����. �̶�, A���� X���� ���� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	vector<int> arr;
	int vec_num = 0;
	int max = 0;
	cin >> vec_num >> max;
	for (int i = 0; i < vec_num; i++)
	{
		int a = 0;
		cin >> a;
		if (a < max)
			cout << a << " ";
	}


}