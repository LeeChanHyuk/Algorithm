#include <iostream>

using namespace std;

int main(void)
{
	int test_case;
	cin >> test_case;
	for (int cases = 1; cases <= test_case; cases++)
	{
		int dalant, unit;
		cin >> dalant >> unit;
		int res = dalant % unit;
		int num = dalant / unit;
		long long result = 1;
		for (int i = 0; i < unit; i++)
			if (res > 0)
			{
				result *= (num + 1);
				res -= 1;
			}
			else
				result *= num;
		cout << "#" << cases << ' ' << result << '\n';
	}
}