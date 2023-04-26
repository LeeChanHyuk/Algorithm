#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    for(int i=0; i<10; i++)
    {
        int test_case;
        scanf("%d", &test_case);
        string word, sentence;
        cin >> word;
        cin >> sentence;
        int index = 0;
        int result = 0;
        while (index + word.size() < sentence.size())
        {
            index = sentence.find(word, index);
            if (index != -1)
            {
                index += 1; // word can be one char
                result += 1;
            }
            else
                break;
        }
        printf("#%d %d\n", test_case, result);
    }
    return 0;
}