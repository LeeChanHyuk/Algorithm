// ConsoleApplication8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

int first_function(int input_num)
{
	int result = 0;
	for (int i = 1; 3 * i <= input_num; i++)
		result += 3 * i;
	for (int i = 1; 5 * i <= input_num; i++)
		result += 5 * i;
	for (int i = 1; 15 * i <= input_num; i++)
		result -= 15 * i;
	return result;
}

int second_function(int arr[], int N)
{
	int arr1[1001] = { 0 };
	for (int i = 0; i < N; i++)
	{
		int num = arr[i];
		if (num <= 100)
			if (arr1[100 - num] == 1)
				return 1;
		arr1[num] = 1;
	}
	return 0;
}

int third_function(int num)
{
	for (int i = 0; i*i <= num; i++)
		if (i*i == num)
			return 1;
	return 0;
}

int fourth_function(int num)
{
	int val = 1;
	while (2 * val < num)
		val *= 2;
	return val;
}



int main()
{
	int num = first_function(27639);
	printf("%d\n",num);
	int arr2[4] = { 4,13,63,87 };
	int num2 = second_function(arr2, 4);
	printf("%d\n", num2);
	int num3 = third_function(756580036);
	printf("%d\n", num3);
	int num4 = fourth_function(97615282);
	printf("%d\n", num4);
    return 0;
}

