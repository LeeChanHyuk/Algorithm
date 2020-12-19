#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
int arr[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num;
    cin >> n >> num;
    vector<int> alphabets;
    for (int i = 0; i < num; i++)
    {
        char temp;
        cin >> temp;
        alphabets.push_back((int)temp);
    }
    vector<int> alphabets_sort(num, 0);
    fill(alphabets_sort.begin() + n, alphabets_sort.end(), 1);
    int count = 0;
    sort(alphabets.begin(), alphabets.end());
    do
    {
        int a = 0, b = 0;
        for (int i = 0; i < num; i++)
        {
            if (alphabets_sort[i] == 1)
                continue;
            if ((char)alphabets[i] == 'a' || (char)alphabets[i] == 'e' || (char)alphabets[i] == 'i' || (char)alphabets[i] == 'o' || (char)alphabets[i] == 'u')
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        if (a > 0 && b > 1)
        {
            for (int i = 0; i < num; i++)
                if (alphabets_sort[i] == 0)
                    cout << (char)alphabets[i];
            cout << '\n';
        }
        /* code */
    } while (next_permutation(alphabets_sort.begin(), alphabets_sort.end()));

    return 0;
}