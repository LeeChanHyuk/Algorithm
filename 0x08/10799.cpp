#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
using namespace std;

char stick[110000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.getline(stick, 100001);
    stack<char> many_stick;
    int many = 0; // 막대기의 개수
    int sum = 0;  // 잘려진 후의 총 막대기 수.
    for (int i = 0; i < 100001; i++)
    {
        if (stick[i] == '\0')
            break;
        else if (stick[i] == '(')
        {
            many++;
            sum++;
            many_stick.push(stick[i]);
        }
        else if (stick[i] == ')')
        {
            if (many_stick.top() == '(')
            {
                many--;
                sum--;
                sum = sum + many;
                many_stick.pop();
            }
            else if (many_stick.top() == ')')
            {
                many--;
                many_stick.pop();
            }
        }
    }
    printf("%d", sum);
    return 0;
}