#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    int test_case = 0;
    scanf("%d", &test_case);
    for (int i=0; i<test_case; i++)
    {
        int n = 0;
        scanf("%d", &n);
        int arr[10] = {0};
        int count_number = 0;
        int multiple_num = 1;
        while (count_number < 10)
        {
            int temp = n * multiple_num;
            while (temp > 0)
            {
                int res = temp % 10;
                if (arr[res] == 0)
                {
                    arr[res] += 1;
                    count_number += 1;
                }
                temp = temp / 10;
            }
            multiple_num += 1;
        }
        printf("%d\n", (n * (multiple_num-1)));
    }
    return 0;
}