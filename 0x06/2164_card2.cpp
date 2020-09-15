#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

void push(int *arr, int num, int *tail)
{
    arr[*tail] = num;
    (*tail)++;
}

int pop(int *arr, int *head, int *tail)
{
    if (*head != *tail)
    {
        int a = arr[*head];
        (*head)++;
        return a;
    }
    else
    {
        return 0;
        printf("-1\n");
    }
}

void front(int *arr, int head, int tail)
{
    if (head != tail)
        printf("%lld\n", arr[head]);
    else
    {
        printf("-1\n");
    }
}

void back(int *arr, int tail, int head)
{
    if (head != tail)
        printf("%lld\n", arr[tail - 1]);
    else
    {
        printf("-1\n");
    }
}

void size(int *arr, int head, int tail)
{
    printf("%d\n", tail - head);
}

void empty(int head, int tail)
{
    if (head == tail)
        printf("1\n");
    else
    {
        printf("0\n");
    }
}
int queue1[6000000];
int main(void)
{
    int head = 0, tail = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int card_num = 0;
    scanf("%d", &card_num);
    for (int i = 1; i <= card_num; i++)
    {
        push(queue1, i, &tail);
    }
    while (1)
    {
        int a = pop(queue1, &head, &tail);
        if (tail - head == 1)
        {
            printf("%d", queue1[head]);
            break;
        }
        int b = pop(queue1, &head, &tail);
        push(queue1, b, &tail);
        if (tail - head == 1)
        {
            printf("%d", queue1[head]);
            break;
        }
    }
    return 0;
}