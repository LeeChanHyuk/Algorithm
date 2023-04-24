#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int demical[7] = {2, 3, 5, 7, 11, 13, 17};

int combination(int n, int r)
{
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(void)
{
    int test_case;
    scanf("%d", &test_case);
    for(int cases=1; cases<=test_case; cases++)
    {
        float probA, probB;
        scanf("%f %f", &probA, &probB);
        float total_probability_A = 0.0f;
        float total_probability_B = 0.0f;
        for (int i=0; i<7; i++)
        {
            float probability_A = (pow((probA / 100), demical[i]) * pow((1-(probA / 100)), 18-demical[i])); // A가 N개 중에 2개 완제품을 만들 확률.
            float probability_B = (pow((probB / 100), demical[i]) * pow((1-(probB / 100)), 18-demical[i]));
            int total_case = combination(18, demical[i]);
            total_probability_A += (probability_A * total_case);
            total_probability_B += (probability_B * total_case);
        }
        printf("#%d %f\n", cases, 1-((1-total_probability_A)*(1-total_probability_B)));
    }
    return 0;
}