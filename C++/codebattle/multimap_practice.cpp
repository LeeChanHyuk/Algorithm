#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

struct compare
{
    int data;
    compare* prev;
    compare* next;
};

int main(void)
{
    unordered_multimap<string, int> um;
    um.insert(make_pair("string, 1", 1));
    cout << um.find("string, 1")->first;
    compare* cp1 = new compare();
    cp1->data = 1;
    cout << cp1->data << '\n';
    compare cp2;
    cp2.data = 2;
    cout << cp2.data << '\n';
    return 0;
}