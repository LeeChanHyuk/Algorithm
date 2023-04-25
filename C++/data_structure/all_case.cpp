#include <stdio.h>
#include <iostream>

using namespace std;

void powerset_bit(int n) // 즉, 이건 1~n을 비트로 나타낼 때, 비트 하나하나가 하나의 원소를 나타낼 수 있다는 것을 이용한 법칙. 여기서는 1, 2, 3을 나타냄.
{
    for(int i=0; i< (1<<n); i++)
    {
        // i의 j번째 bit가 1인지 검사하는 코드
        for(int j=0; j<n; j++)
        {
            if(i & (1 << j))
                printf("%d ", j+1); // {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}
        }
        printf("\n");
    }
}

int main(void)
{
    powerset_bit(3);
    return 0;
}