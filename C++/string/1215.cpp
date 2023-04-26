#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool compare(string word)
{
    for(int i=0; i<word.size()>>1; i++)
        if(word[i] != word[word.size()-1-i])
            return false;
    return true;
}

void transpose(char(* a)[8], char(* b)[8])
{
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            b[j][i] = a[i][j];
}

int main(void)
{
    for(int test_case=1; test_case<=10; test_case++)
    {
        int sentence_length;
        scanf("%d", &sentence_length);
        char sentences[8][8];
        char sentences2[8][8];
        int result = 0;
        for(int i=0; i<8; i++)
        {
            cin >> sentences[i];
            string a(sentences[i]);
            for(int j=0; j<9-sentence_length; j++)
                if (compare(string(sentences[i]).substr(j, sentence_length)))
                    result += 1;
        }
        transpose(sentences, sentences2);
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<9-sentence_length; j++)
                if (compare(string(sentences2[i]).substr(j, sentence_length)))
                    result += 1;
        }
        printf("#%d %d\n", test_case, result);
    }
    return 0;
}