#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

void push(int *arr, int num, int *tail)
{
    arr[*tail] = num;
    (*tail)++;
}

void pop(int *arr, int *head, int *tail)
{
    if (*head != *tail)
    {
        printf("%lld\n", arr[*head]);
        (*head)++;
    }
    else
    {
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
    int command_num = 0;
    cin >> command_num;
    while (command_num--)
    {
        char command[100];
        scanf("%s", command);
        printf("%s", command);
        if (!strcmp(command, "push"))
        {
            int num = 0;
            scanf("%d", &num);
            push(queue1, num, &tail);
        }
        else if (!strcmp(command, "front"))
        {
            front(queue1, head, tail);
        }
        else if (!strcmp(command, "back"))
        {
            back(queue1, tail, head);
        }
        else if (!strcmp(command, "size"))
        {
            size(queue1, head, tail);
        }
        else if (!strcmp(command, "pop"))
        {
            pop(queue1, &head, &tail);
        }
        else // command == empty
        {
            empty(head, tail);
        }
    }
    return 0;
}