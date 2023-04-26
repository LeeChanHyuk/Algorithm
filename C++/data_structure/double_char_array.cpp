#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    char animal[5][20];
    for(int i=0; i<5; i++)
        scanf("%s", animal[i]);
    for(int i=0; i<5; i++)
        cout << string(animal[i]) << ' ';
    cout<<'\n';
}