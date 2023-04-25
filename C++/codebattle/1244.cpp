#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int num_board[6] = {0};
int biggest_num[6] = {0};
int all_number[10][1000000] = {0};
int temp;

int fill_num_board(int num)
{
    int number = num;
    int res = num;
    int count = 0;
    int arr[6] = {0};
    while (number != 0)
    {
        res = number % 10;
        arr[count] = res;
        number /= 10;
        count += 1;
    }
    for(int i=0; i<count; i++)
    {
        num_board[count-1-i] = arr[i];
        biggest_num[count-1-i] = arr[i];
    }
    return count;
}

bool compare(int count, int k)
{
    int semi_count = count;
    int num=0;
    while (semi_count > 0)
    {
        num += num_board[count-semi_count] * pow(10, semi_count-1);
        semi_count -= 1;
    }
    if (all_number[k][num] != 0)
        return false;
    else
    {
        all_number[k][num] += 1;
        return true;   
    }
}

void back_tracking(int k, int count, int change_num, int index)
{
    if (k == change_num)
    {
        int num = 0;
        for(int l=0; l<count; l++)
        {
            if (num_board[l] > biggest_num[l])
                for(int m=0; m<count; m++)
                    biggest_num[m] = num_board[m];
            else if (num_board[l] == biggest_num[l])
                continue;
            else
                break;
        }
    }
    else
    {
        for(int i=index; i<count; i++)
        {
            for(int j=i+1; j<count; j++)
            {
                if (i==j)
                    continue;
                temp = num_board[i];
                num_board[i] = num_board[j];
                num_board[j] = temp;
                bool check = compare(count, k);
                if (check)
                    back_tracking(k+1, count, change_num, i);
                temp = num_board[j];
                num_board[j] = num_board[i];
                num_board[i] = temp;
            }
        }
    }
}

int main(void)
{
    int test_case;
    scanf("%d", &test_case);
    for(int cases=1; cases<=test_case; cases++)
    {
        memset(num_board, -1, sizeof(num_board));
        memset(biggest_num, -1, sizeof(biggest_num));
        int num, change_num;
        scanf("%d %d", &num, &change_num);
        int count = fill_num_board(num);
        back_tracking(0, count, change_num, 0);
        int result = 0;
        for(int i=0; i<count; i++)
            result += (biggest_num[i] * pow(10, count-1-i));
        printf("#%d %d\n", cases, result);
    }
    return 0;
}