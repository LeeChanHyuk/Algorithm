#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>

using namespace std;

struct sticker
{
    int col;
    int row;
    int area[10][10];
};

vector<sticker> stickers;

// bruteforce로 풀어보자

int width, height, sticker_num;
int notebook[40][40];

// 마지막으로 붙인 스티커의 제일 윗부분 제일 오른쪽 좌표를 final_position에 저장한다.

bool can_paste(int num, int x, int y, int rotation) // 몇 번째 스티커를, 어디에
{
    int row = stickers[num].row;
    int col = stickers[num].col;
    if (rotation == 0)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (stickers[num].area[i][j] == 1 && notebook[y + i][x + j] == 1)
                    return false;
                if (x + col > width || y + row > height)
                    return false;
            }
    }
    else if (rotation == 1) // 90도 회전
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (stickers[num].area[i][j] == 1 && notebook[y + j][x + row - 1 - i] == 1)
                    return false;
                if (x + row > width || y + col > height)
                    return false;
            }
    }
    else if (rotation == 2) // 180도 회전
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (stickers[num].area[i][j] == 1 && notebook[y + row - 1 - i][x + col - 1 - j] == 1)
                    return false;
                if (x + col > width || y + row > height)
                    return false;
            }
    }
    else if (rotation == 3) // 270도 회전
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (stickers[num].area[i][j] == 1 && notebook[y + col - 1 - j][x + i] == 1)
                    return false;
                if (x + row > width || y + col > height)
                    return false;
            }
    }
    return true;
}

void paste(int num, int x, int y, int rotation)
{
    int row = stickers[num].row;
    int col = stickers[num].col;

    if (rotation == 0)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (rotation == 0) // 정방향
                    if (stickers[num].area[i][j] == 1)
                        notebook[y + i][x + j] = 1;
    }
    else if (rotation == 1) // 90도 회전
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (stickers[num].area[i][j] == 1)
                    notebook[y + j][x + row - 1 - i] = 1;
    }
    else if (rotation == 2) // 180도 회전
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (stickers[num].area[i][j] == 1)
                    notebook[y + row - 1 - i][x + col - 1 - j] = 1;
    }
    else if (rotation == 3) // 270도 회전
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (stickers[num].area[i][j] == 1)
                    notebook[y + col - 1 - j][x + i] = 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> height >> width >> sticker_num;
    // 스티커 정보 받아오기
    for (int k = 0; k < sticker_num; k++)
    {
        int col, row;
        cin >> row >> col;
        sticker sticker;
        sticker.row = row;
        sticker.col = col;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> sticker.area[i][j];
        stickers.push_back(sticker);
    }
    // 시간초과뜨면 마지막 위치 기억하는걸로 바꾸기(paste에서 위치 얻고, i=0 j=0 대신 위치 넣어주면 될 듯)
    bool pass = false;
    for (int k = 0; k < sticker_num; k++)
    {
        pass = false;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (can_paste(k, j, i, 0))
                {
                    paste(k, j, i, 0);
                    pass = true;
                    break;
                }
            }
            if (pass)
                break;
        }
        if (pass)
            continue;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (can_paste(k, j, i, 1))
                {
                    paste(k, j, i, 1);
                    pass = true;
                    break;
                }
            }
            if (pass)
                break;
        }
        if (pass)
            continue;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (can_paste(k, j, i, 2))
                {
                    paste(k, j, i, 2);
                    pass = true;
                    break;
                }
            }
            if (pass)
                break;
        }
        if (pass)
            continue;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (can_paste(k, j, i, 3))
                {
                    paste(k, j, i, 3);
                    pass = true;
                    break;
                }
            }
            if (pass)
                break;
        }
    }
    int count = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            if (notebook[i][j] == 1)
                count++;
        }
    cout << count;

    return 0;
}