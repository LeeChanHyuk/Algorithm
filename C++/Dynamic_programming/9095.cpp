#include <iostream>
#include <string.h>

using namespace std;

long long D[11] = {0};

int main(void)
{
    fill_n(D, 11, 10);
    int test_case = 0;
    int n=0;
    scanf("%d", &test_case);
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    D[4] = 7;
    for(int i=0; i<test_case; i++)
    {
        scanf("%d", &n);
        for(int j=5; j<=n; j++)
            D[j] = D[j-1] + D[j-2] + D[j-3];
        printf("%lld\n", D[n]);
    }
    return 0;
}