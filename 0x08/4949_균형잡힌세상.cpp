#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        int go = 1;
        char word[101];
        cin.getline(word, 101);
        stack<char> word_stack;
        for (int i = 0; i < sizeof(word) / sizeof(char); i++)
        {
            if (word[i] == '[')
                word_stack.push(word[i]);
            else if (word[i] == '(')
                word_stack.push(word[i]);
            else if (word[i] == ']')
            {
                if (!word_stack.empty())
                {
                    char a = word_stack.top();
                    if (a == '[')
                        word_stack.pop();
                    else
                    {
                        go = 0;
                        break;
                    }
                }
                else
                {
                    go = 0;
                    break;
                }
            }
            else if (word[i] == ')')
            {
                if (!word_stack.empty())
                {
                    char a = word_stack.top();
                    if (a == '(')
                        word_stack.pop();
                    else
                    {
                        go = 0;
                        break;
                    }
                }
                else
                {
                    go = 0;
                    break;
                }
            }
            else if (word[0] == '.' && word[1] == '\0')
            {
                go = 2;
                break;
            }
            else if (word[i] == '\0')
                break;
        }
        if (!word_stack.empty())
            go = 0;
        if (go == 0)
        {
            printf("no\n");
        }
        else if (go == 2)
            break;
        else
            printf("yes\n");
    }
    return 0;
}