#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;



int main()
{
	// 정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.
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