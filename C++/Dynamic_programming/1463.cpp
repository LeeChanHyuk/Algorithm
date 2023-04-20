#include <iostream>
#include <string.h>

using namespace std;

long long D[1000002] = {0};

int main(void)
{
    int n=0;
    scanf("%d", &n);
    fill_n(D, 1000002, n-1);
    D[1] = 0;
    D[2] = 1;
    D[3] = 1; // 즉, 각 index가 해당 숫자를 1에서 몇 번 연산해야 하는지를 나타내고 있다.
    for(int i=4; i<1000002; i++)
    {
        D[i] = D[i-1] + 1;
        if (i%2==0)
            D[i] = min(D[i/2]+1, D[i]);
        if (i%3==0)
            D[i] = min(D[i/3]+1, D[i]);
    }
    printf("%lld", D[n]);
    return 0;
}