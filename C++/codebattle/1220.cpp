#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int board[102][102] = {0};

int count(void)
{
    int result = 0;
    for(int j=0; j<100; j++)
    {
        bool find_red = false;
        bool find_blue = false;
        for(int i=0; i<100; i++)
        {
            if(find_blue == true && board[i][j] == 1)
            {
                find_blue = false;
                find_red = true;
            }
            else if(find_red == true && board[i][j] == 2)
            {
                result += 1;
                find_red = false;
                find_blue = true;
            }
            else if(board[i][j] == 1)
                find_red = true;
        }
    }
    return result;
}

int main(void)
{
    int height = 100;
    for(int test_case=1; test_case<=10; test_case++)
    {
        scanf("%d", &height);
        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++)
                scanf("%d", &board[i][j]);
        int result = count();
        printf("#%d %d\n", test_case, result);
    }

    return 0;
}