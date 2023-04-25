#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {

    set<int> s;

    s.insert(1);
    s.insert(200);
    s.insert(-1);
    s.insert(3);

    int arr[] = { 1, 2, 3, 4, 5, 6 };
    set<int> s1(s.begin(), s.end());    //output : s1 = -1, 1, 3, 200
    
    set<int> s2(arr, arr + 6);        //output : s2 = 1, 2, 3, 4, 5, 6
    
    set<int> s3(s1);        //output : s3 = -1, 1, 3, 200
    
    set<int> s4 = s2;        //output : s4 = 1, 2, 3, 4, 5, 6
    
    for(auto it = s1.begin(); it != s1.end(); it++)
    {
        cout<<*it<<'\n';
    }
    return 0;
}