#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void)
{
    set<pair<string, int>> s;
    s.insert(make_pair("string", 1));
    cout << (*(s.begin())).first << '\n';
    return 0;
}