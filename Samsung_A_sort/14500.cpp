#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int width, height;
int board[510][510];
int sticker[2][4][4];
int which_sticker = 1;

void sticker_rotate(int num)
{
    // 스티커 인덱싱
    int now = which_sticker;
    int news = 1;
    if (now)
        news = 0;
    // 스티커 로테이션은 무조건 오른쪽 90도로만 하자. 어느쪽으로하든 어차피 4번 돌리면 원형나옴ㅎㅎ
    if (num)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                sticker[news][j][3 - i] = sticker[now][i][j];
    }
    else
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                sticker[news][i][3 - j] = sticker[now][i][j];
    }
    if (which_sticker)
        which_sticker = 0;
    else
        which_sticker = 1;
}

void sticker_make(int num)
{
    switch (num)
    {
    case 0:
    {
        sticker[which_sticker][0][0] = 1;
        sticker[which_sticker][0][1] = 1;
        sticker[which_sticker][0][2] = 1;
        sticker[which_sticker][0][3] = 1;
        break;
    }
    case 1:
    {
        sticker[which_sticker][0][0] = 1;
        sticker[which_sticker][0][1] = 1;
        sticker[which_sticker][1][0] = 1;
        sticker[which_sticker][1][1] = 1;
        break;
    }
    case 2:
    {
        sticker[which_sticker][0][0] = 1;
        sticker[which_sticker][0][1] = 1;
        sticker[which_sticker][0][2] = 1;
        sticker[which_sticker][1][0] = 1;
        break;
    }
    case 3:
    {
        sticker[which_sticker][0][0] = 1;
        sticker[which_sticker][0][1] = 1;
        sticker[which_sticker][1][1] = 1;
        sticker[which_sticker][1][2] = 1;
        break;
    }
    case 4:
    {
        sticker[which_sticker][0][0] = 1;
        sticker[which_sticker][0][1] = 1;
        sticker[which_sticker][0][2] = 1;
        sticker[which_sticker][1][1] = 1;
        break;
    }
    }
}

void sticker_reset()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            sticker[which_sticker][i][j] = 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> height >> width;
    for (int i = 3; i < height + 3; i++)
        for (int j = 3; j < width + 3; j++)
            cin >> board[i][j];
    int sum = 0;
    int result = 0;
    for (int a = 0; a < 5; a++)
    {
        sticker_reset();
        sticker_make(a);
        for (int i = 0; i < height + 6; i++)
            for (int j = 0; j < width + 6; j++)
            {
                for (int r = 0; r < 8; r++)
                {
                    if (r == 4)
                        sticker_rotate(0);
                    for (int k = 0; k < 4; k++)
                        for (int l = 0; l < 4; l++)
                            sum += board[i + k][j + l] * sticker[which_sticker][k][l];
                    if (sum > result)
                        result = sum;
                    sum = 0;
                    sticker_rotate(1);
                }
            }
    }
    cout << result;
    return 0;
}