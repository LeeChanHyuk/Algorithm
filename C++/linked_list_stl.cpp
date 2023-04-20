#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    list<int> int_list;
    list<int>::iterator cursor = int_list.begin();
    int_list.insert(cursor, 1);
    int_list.insert(cursor, 2);
    //int_list.insert(cursor, 3);
    while (1)
    {
        cout << *cursor << " ";
        cursor++;
    }
    return 0;
}