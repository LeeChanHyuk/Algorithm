#include <string>
#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;

void init(unordered_map<string, int>& um, unordered_map<int, string>& um2)
{
    um["ZRO"] = 0;
    um["ONE"] = 1;
    um["TWO"] = 2;
    um["THR"] = 3;
    um["FOR"] = 4;
    um["FIV"] = 5;
    um["SIX"] = 6;
    um["SVN"] = 7;
    um["EGT"] = 8;
    um["NIN"] = 9;

    um2[0] = "ZRO";
    um2[1] = "ONE";
    um2[2] = "TWO";
    um2[3] = "THR";
    um2[4] = "FOR";
    um2[5] = "FIV";
    um2[6] = "SIX";
    um2[7] = "SVN";
    um2[8] = "EGT";
    um2[9] = "NIN";
}

int arr[10] = {0};

int main(void)
{
    int test_case, length;
    string test_case_trash, word;
    cin>>test_case;
    unordered_map<string, int> um;
    unordered_map<int, string> um2;
    init(um, um2);
    for(int i=0; i<test_case; i++)
    {
        memset(arr, 0, sizeof(arr));
        cin >> test_case_trash >> length;
        while (length > 0)
        {
            cin >> word;
            arr[um[word]] += 1;
            length -= 1;
        }
        cout << '#' << i+1 << '\n';
        for(int j=0; j<10; j++)
            for(int k=0; k<arr[j]; k++)
                cout << um2[j] << ' ';
        cout << '\n';
    }
    return 0;
}