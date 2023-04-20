#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int bit_transition(int num)
{
    int res = num;
    int count = 0;
    while (res != 1)
    {
        res = res / 2;
        count += 1;
    }
    return count;
}

int main(void)
{
    int test_case = 0;
    scanf("%d", &test_case);
    for(int i=1; i<=test_case; i++)
    {
        int N = 0;
        long long M = 0;
        int bit_array[31] = {0};
        scanf("%d %lld", &N, &M);
        int res = M;
        int temp_bit = 0;
        int original_num = 0;
        while (res != 0)
        {
            temp_bit = bit_transition(res);
            bit_array[temp_bit] += 1;
            res -= pow(2, temp_bit);
        }
        bool result = true;
        for(int j=0; j<N; j++)
            if(bit_array[N-1-j]==0)
                result = false;

        if (result == true)
            printf("#%d ON\n", i);
        else
            printf("#%d OFF\n", i);
    }
    return 0;
}