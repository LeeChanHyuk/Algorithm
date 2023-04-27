#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char node[2002];
double node_double[2002];

double in_order(int index)
{
    if (node[index] == '+')
    {
        double val = in_order(index * 2) + in_order((index * 2) + 1);
        return val;
    }
    else if (node[index] == '-')
    {
        double val = in_order(index * 2) - in_order((index * 2) + 1);
        return val;
    }
    else if (node[index] == '*')
    {
        double val = in_order(index * 2) * in_order((index * 2) + 1);
        return val;
    }
    else if (node[index] == '/')
    {
        double left = in_order((index * 2));
        double right = in_order((index * 2) + 1);
        if (right == 0)
            return 0.0;
        else
        {
            double val = in_order(index * 2) / in_order((index * 2) + 1);
            return val;
        }
    }
    if (node[index] == 'a' && node_double[index] != 0)
        return node_double[index];
    else
        return 0;
}

int main(void)
{
    for(int test_case=1; test_case <=10; test_case++)
    {
        memset(node, 'a', sizeof(node));
        memset(node_double, 0, sizeof(node_double));
        int n, node_num, temp;
        string data;
        cin >> n; // total_node_number

        // build tree
        for(int i=1; i<=n; i++)
        {
            cin >> node_num >> data;
            if (data == "+" || data == "-" || data == "*" || data == "/")
            {
                node[i] = data[0];
                cin >> temp;
                cin >> temp;
            }
            else
                node_double[i] = stod(data);
        }
        int result = in_order(1);
        cout << "#" << test_case << ' ' << result << '\n';
    }

    return 0;
}