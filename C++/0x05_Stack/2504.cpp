#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>

using namespace std;

/*4개의 기호 ‘(’, ‘)’, ‘[’, ‘]’를 이용해서 만들어지는 괄호열 중에서 올바른 괄호열이란 다음과 같이 정의된다.

한 쌍의 괄호로만 이루어진 ‘()’와 ‘[]’는 올바른 괄호열이다. 
만일 X가 올바른 괄호열이면 ‘(X)’이나 ‘[X]’도 모두 올바른 괄호열이 된다. 
X와 Y 모두 올바른 괄호열이라면 이들을 결합한 XY도 올바른 괄호열이 된다.
예를 들어 ‘(()[[]])’나 ‘(())[][]’ 는 올바른 괄호열이지만 ‘([)]’ 나 ‘(()()[]’ 은 모두 올바른 괄호열이 아니다. 우리는 어떤 올바른 괄호열 X에 대하여 그 괄호열의 값(괄호값)을 아래와 같이 정의하고 값(X)로 표시한다. 

‘()’ 인 괄호열의 값은 2이다.
‘[]’ 인 괄호열의 값은 3이다.
‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.
예를 들어 ‘(()[[]])([])’ 의 괄호값을 구해보자.  ‘()[[]]’ 의 괄호값이 2 + 3×3=11 이므로  ‘(()[[ ]])’의 괄호값은 2×11=22 이다. 그리고  ‘([])’의 값은 2×3=6 이므로 전체 괄호열의 값은 22 + 6 = 28 이다.

여러분이 풀어야 할 문제는 주어진 괄호열을 읽고 그 괄호값을 앞에서 정의한대로 계산하여 출력하는 것이다. */

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    // 종류는 4가지. ( ) [ ]
    stack<char> stack1;
    stack<int> numbers;

    // 들어가고자 하는 문자
    char str1;
    // 들어가 있는 문자
    char str2;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char now = str[i];
        // 잘못된 문자열의 예시. 뭐가 들어가든 스택 맨 위에 있는애가 ) 나 ]면 안된다. 얘들은 드가자마자 바로 숫자로 바뀌어야하는 애들이다.
        // 또 문자열이 끝났는데, 스택안에 숫자하나 말고 다른게 남아있으면 안된다.
        if (!stack1.empty())
        {
            char top = stack1.top();
            if (stack1.top() == ')' || stack1.top() == ']')
            {
                cout << 0;
                return 0;
            }
            else if (stack1.top() == '(')
            {
                if (str[i] == ')')
                {
                    stack1.pop();
                    int out = 2;

                    while (!stack1.empty() && stack1.top() != '[' && stack1.top() != '(' && stack1.top() != ']' && stack1.top() != ')')
                    {
                        out = numbers.top() + out;
                        numbers.pop();
                        stack1.pop();
                    }
                    stack1.push((char)count);
                    count++;
                    numbers.push(out);
                }
                else
                    stack1.push(str[i]);
            }
            else if (stack1.top() == '[')
            {
                if (str[i] == ']')
                {
                    stack1.pop();
                    int out = 3;
                    while (!stack1.empty() && stack1.top() != '[' && stack1.top() != '(' && stack1.top() != ']' && stack1.top() != ')')
                    {
                        out = numbers.top() + out;
                        numbers.pop();
                        stack1.pop();
                    }
                    stack1.push((char)count);
                    count++;
                    numbers.push(out);
                }
                else
                {
                    stack1.push(str[i]);
                }
            }
            else if (stack1.top() != '[' && stack1.top() != '(' && stack1.top() != ']' && stack1.top() != ')') // 숫자가 들어 있을 때
            {
                if (str[i] == ')')
                {
                    int num = numbers.top();
                    numbers.pop();
                    stack1.pop();
                    if (!stack1.empty() && stack1.top() == '(')
                    {
                        int out = num * 2;
                        stack1.pop();
                        while (!stack1.empty() && stack1.top() != '[' && stack1.top() != '(' && stack1.top() != ']' && stack1.top() != ')')
                        {
                            out = numbers.top() + out;
                            numbers.pop();
                            stack1.pop();
                        }
                        stack1.push((char)count);
                        count++;
                        numbers.push(out);
                    }
                }
                else if (str[i] == ']')
                {
                    int num = numbers.top();
                    numbers.pop();
                    stack1.pop();
                    if (!stack1.empty() && stack1.top() == '[')
                    {
                        int out = num * 3;
                        stack1.pop();
                        while (!stack1.empty() && stack1.top() != '[' && stack1.top() != '(' && stack1.top() != ']' && stack1.top() != ')')
                        {
                            out = numbers.top() + out;
                            numbers.pop();
                            stack1.pop();
                        }
                        stack1.push((char)count);
                        numbers.push(out);
                    }
                }
                else
                {
                    stack1.push(str[i]);
                }
            }
        }
        else
        {
            stack1.push(str[i]);
        }
    }
    if (stack1.size() == 1 && numbers.size() == 1)
    {
        cout << numbers.top();
    }
    else
    {
        cout << 0;
    }

    return 0;
}