#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;

void moo_game(int now, int num)
{
    int x1=a.back()+3;
    int x2=a.back()+3+now+3;
    a.push_back(x1);
    a.push_back(x2);    
    for(int i=0; i<a.size(); i++)
    {
        b.push_back(a[i]);
        
        
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    a.push_back(0);
    return 0;
    //a
    //aba
    //abacaba
    //abacabadabacaba
    //0 - 0
    //0 3 7 - 0 3 4
    //0 3 7 10 15 18 21 - 3 4 3 5 3 4
    //                  - 3 4 3 5 3 4 3 6 3 4 3 5 3 4
    // 0
    // 0 3 7
    // 0 3 7 10 15 18 22
    // 0 3 7 10 15 18 22 25 31
}