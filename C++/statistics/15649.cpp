#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
int arr[10] = {0};
int isused[10] = {0};

void permutation(int k)
{
    if (k == m+1)
    {
        for(int j=1; j<k; j++)
            printf("%d ", arr[j]);
        printf("\n");
        return;
    }
    for (int i=k; i<=n; i++)
    {
        arr[k] = i;
        permutation(k+1);
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    permutation(1);
    return 0;
}