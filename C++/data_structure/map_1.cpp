#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
    unordered_map<string, int> um;
    um["string"] = 1;
    cout << um["string"];
    return 0;
}