#include <iostream>

using namespace std;

struct{
    char operation;
    double value;
    int left; // left child node
    int right; // right child node
} nodes[10002];

double post_order(int index)
{
    if (nodes[index].operation == NULL)
        return nodes[index].value;
    else if (nodes[index].operation == '+')
        return post_order(nodes[index].left) + post_order(nodes[index].right);
    else if (nodes[index].operation == '-')
        return post_order(nodes[index].left) - post_order(nodes[index].right);
    else if (nodes[index].operation == '*')
        return post_order(nodes[index].left) * post_order(nodes[index].right);
    else if (nodes[index].operation == '/')
        return post_order(nodes[index].left) / post_order(nodes[index].right);
}

int main(void)
{
    for(int test_case=1; test_case<=10; test_case++)
    {
        for(int i=10001; i!=-1; i--)
        {
            nodes[i].operation = NULL;
            nodes[i].value = -1;
            nodes[i].left = -1;
            nodes[i].right = -1;
        }
        int n, node_num;
        char temp_data[10];
        scanf("%d", &n);
        for(int i=n; i!=0; i--)
        {
            scanf("%d %s", &node_num, temp_data);
            if(temp_data[0] == '+' || temp_data[0] == '-' || temp_data[0] == '*' || temp_data[0] == '/')
            {
                nodes[node_num].operation = temp_data[0];
                scanf("%d %d", &nodes[node_num].left, &nodes[node_num].right);
            }
            else
                nodes[node_num].value = std::strtol(temp_data, nullptr, 10);
        }
        int result = post_order(1);
        printf("#%d %d\n", test_case, result);
    }
    return 0;
}