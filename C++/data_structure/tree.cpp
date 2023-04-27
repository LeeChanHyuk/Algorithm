#include <stdio.h>
#include <iostream>

using namespace std;

void binary_search(int index, int* node, int target)
{
    // 범위 예외 처리 하나.
    // return은 그냥 전역변수로 처리하는게 좋지않을까?
    if(target == node[index])
        cout << index;
    else if (target < node[index])
        binary_search(index*2, node, target);
    else
        binary_search(index*2+1, node, target);
}

int main(void)
{
    int node[100];
    int data[100] = {9, 4, 3, 6, 12, 15, 0, 0, 0, 0, 13, 17};

    return 0;
}