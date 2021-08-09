#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

// 2의 15승은 32768;

pair<int, int> recursive(int walks, int one)
{
    one = one / 4;
    pair<int, int> p;
    if (one == 1)
    {
        if (walks == 1)
            return {1, 1};
        else if (walks == 2)
            return {1, 2};
        else if (walks == 3)
            return {2, 2};
        else
            return {2, 1};
    }
    else
    {
        int width = (int)sqrt(one);
        if (walks <= one) // 1구역
        {
            p = recursive(walks, one);
            return {p.second, p.first};
        }
        else if (walks <= one * 2) // 2구역
        {
            p = recursive(walks - one, one);
            return {p.first, p.second + width};
        }
        else if (walks <= one * 3) // 3구역
        {
            p = recursive(walks - one * 2, one);
            return {p.first + width, p.second + width};
        }
        else // 4구역
        {
            p = recursive(walks - one * 3, one);
            return {2 * width - p.second + 1, width - p.first + 1};
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 전부 다를 구할 필요는 없다. 그냥 어느 구역에 속하는 지를 알아야 한다.
    int walks = 0;
    int width = 0;
    cin >> width >> walks;
    int one = 1;
    while (one < walks)
        one *= 4;
    pair<int, int> p = recursive(walks, one);
    cout << p.first << ' ' << p.second << '\n';

    return 0;
}