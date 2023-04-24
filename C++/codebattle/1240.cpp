#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string zero = "0001101";
string one = "0011001";
string two = "0010011";
string three = "0111101";
string four = "0100011";
string five = "0110001";
string six = "0101111";
string seven = "0111011";
string eight = "0110111";
string nine = "0001011";

int compare_with_digit(string word)
{
    if (word == zero)
        return 0;
    else if (word == one)
        return 1;
    else if (word == two)
        return 2;
    else if (word == three)
        return 3;
    else if (word == four)
        return 4;
    else if (word == five)
        return 5;
    else if (word == six)
        return 6;
    else if (word == seven)
        return 7;
    else if (word == eight)
        return 8;
    else if (word == nine)
        return 9;
    return 0;
}

int main(void)
{
    int test_case;
    int code[8] = {0};
    scanf("%d", &test_case);
    for(int tcase=1; tcase<=test_case; tcase++)
    {
        int n, m, i;
        string line;
        scanf("%d %d", &n, &m);
        int odd_number = 0;
        int even_number = 0;
        for (int k=0; k<n; k++)
        {
            i = m-1;
            cin >> line;
            while (line[i] == '0') i--;
            if (i<=0)
                continue;
            if (odd_number+even_number == 0)
            {
                int start_num = i-55;
                int code_order = 0;
                for(int j=start_num; j<i; j+=7)
                {
                    code[code_order] = compare_with_digit(line.substr(j, 7));
                    if ((code_order & 1) == 0)
                        odd_number += code[code_order];
                    else
                        even_number += code[code_order];
                    code_order += 1;
                }
                if (((3*odd_number) + even_number) % 10 == 0)
                    printf("#%d %d\n", tcase, odd_number+even_number);
                else
                    printf("#%d 0\n", tcase);
            }
        }

    }
    return 0;
}