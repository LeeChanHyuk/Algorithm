#include <iostream>
#include <string.h>

using namespace std;

long long D[10002][16] = {0};

int main(void)
{
    int test_case = 0;
    scanf("%d", &test_case);
    for (int each_case=0; each_case<test_case; each_case++)
    {
        string student_manager_list;
        cin >> student_manager_list;
        long long result = 0;
        memset(D, 0, sizeof(D));
        for(int day=0; day<student_manager_list.length(); day++)
        {
            int student_manager = 1 << (student_manager_list[day] - 'A'); // Distance from 'A'
            for (int i=1; i<16; i++) // all case of student come in yesterday (15 case per day)
            {
                if (day == 0)
                {
                    if((i&student_manager)&&(i&1))
                        D[day][i] = 1;
                }
                else
                {
                    if (D[day-1][i] != 0)
                    {
                        for(int j=1; j<16; j++) // all case of student come in today (15 case per day)
                        {
                            if ((i&j) && (student_manager&j))
                            {
                                D[day][j] += D[day-1][i];
                                D[day][j] %= 1000000007;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1; i<16; i++) // all case in final day (The final day is including all of the case in all days)
        {
            result += D[student_manager_list.length()-1][i];
            result %= 1000000007;
        }
        printf("#%d %llu\n", each_case+1, result);
    }
    return 0;
}