#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>

using namespace std;

double product_positions[10] = { 0 };
double product_mass[10] = { 0 };

void binary_search(int n)
{
	double mid, low, high;
	set<double> results;
	for (int i = 0; i < n; i++)
	{
		low = product_positions[i];
		high = product_positions[i + 1];
		while (low <= high)
		{
			mid = (low + high) / 2;
			double left_power = 0;
			double right_power = 0;
			for (int i = 0; i < n; i++)
			{
				if (mid > product_positions[i])
					left_power += (product_mass[i] / ((mid - product_positions[i]) * (mid - product_positions[i])));
				else if (mid < product_positions[i])
					right_power += (product_mass[i] / ((mid - product_positions[i]) * (mid - product_positions[i])));
			}
			if (abs(left_power - right_power) < 1e-13)
				break;
			else if (left_power > right_power)
				low = mid + (1e-13);
			else if (right_power > left_power)
				high = mid - (1e-13);
		}
		if (results.find(mid) == results.end())
		{
			cout << mid << ' ';
			results.insert(mid);
		}
	}
	cout << '\n';
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	cout << fixed;
	cout.precision(10);
	int test_case;
	cin >> test_case;
	for (int cases = 1; cases <= test_case; cases++)
	{
		int n;
		cin >> n;
		int position, mass;
		memset(product_positions, 0, sizeof(product_positions));
		memset(product_mass, 0, sizeof(product_mass));
		for (int i = 0; i < n; i++)
			cin >> product_positions[i];
		for (int i = 0; i < n; i++)
			cin >> product_mass[i];
		cout << "#" << cases << ' ';
		binary_search(n);
	}
	return 0;
}