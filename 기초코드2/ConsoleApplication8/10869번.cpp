#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;



int main()
{
	long A = 0, B = 0, C = 0;
	cin >> A >> B >> C;
	if (A <= B && A <= C)
	{
		cout << A << " ";
		if (B <= C)
		{
			cout << B << " " << C << " ";
		}
		else
			cout << C << " " << B << " ";
	}
	if (B <= A && B <= C)
	{
		cout << B << " ";
		if (A <= C)
		{
			cout << A << " " << C << " ";
		}
		else
			cout << C << " " << A << " ";
	}
	if (C <= B && C <= A)
	{
		cout << C << " ";
		if (A <= B)
		{
			cout << A << " " << B << " ";
		}
		else
			cout << B << " " << A << " ";
	}


}