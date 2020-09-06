#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string init;
    
    cin >> init;
    
    list<char> words;
    for(auto c : init) 
        words.push_back(c);
    auto pivot = words.end();
    int num;
    cin >> num;
    // 초기 설정 : 문자 받고, 커서는 문자열의 마지막에 위치 중.
    while(num--)
    {
        char op;
        cin>> op;
        if(op == 'P')
        {
            char add;
            cin >> add;
            words.insert(pivot,add);
        }
        else if(op == 'L')
        {
            if(pivot != words.begin())
                pivot--;
        }
        else if(op == 'D')
        {
            if(pivot != words.end())
                pivot++;
        }
        else
        {
            if(pivot != words.begin())
            {
                pivot--;
                pivot = words.erase(pivot);
            }
        }
    }
    for(auto c : words)
        cout<<c;
}