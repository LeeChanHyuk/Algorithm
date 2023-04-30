#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int words[26] = {0};

        string word;
        cin>>word;
        for(int i=0; i<word.size(); i++)
        {
            char a = (char)word[i];
            words[a-'a']++;
        }
        for(int i=0; i<sizeof(words)/4; i++)
        {
            cout<<words[i]<<" ";
        }
        
}