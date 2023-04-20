#include <iostream>

using namespace std;

long long D[100] = {0};

int main(void)
{
    D[0] = 0;
    D[1] = 1;
    D[2] = 1;
    D[3] = 2;
    for(int i=4; i<100; i++)
    {
        D[i] = D[i-1] + D[i-2];
    }
    int n = 0;
    scanf("%d", &n);
    printf("%lld", D[n]);
    return 0;
}