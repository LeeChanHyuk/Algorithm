#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char node[101];

int calculate_child_node_number(int* child_node_num, int n)
{
    int number = 1;
    while (number <= n)
        number = number << 1;
    return number >> 1;
}

void in_order(int index)
{
    if (node[index] == 'a')
        return;
    in_order(index * 2);
    cout << node[index];
    in_order((index * 2) + 1);
}

int main(void)
{
    int child_node_num[101];
    for(int test_case=1; test_case <=10; test_case++)
    {
        memset(node, 'a', sizeof(node));
        memset(child_node_num, 0, sizeof(child_node_num));
        int n, node_num, temp;
        char data;
        cin >> n; // total_node_number
        int leaf_start_num = calculate_child_node_number(child_node_num, n);

        // left node number count phase
        fill_n(child_node_num + 1, (leaf_start_num >> 1) - 1, 2);
        for(int i=leaf_start_num; i<=n; i++)
            child_node_num[i/2] += 1;

        // build tree
        for(int i=1; i<=n; i++)
        {
            cin >> node_num >> data;
            node[i] = data;
            for(int j=0; j<child_node_num[i]; j++)
                cin >> temp;
        }
        cout << "#" << test_case << ' ';
        in_order(1);
        cout << '\n';
    }

    return 0;
}