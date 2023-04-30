#include <iostream>
#include <string.h>

using namespace std;

struct{
    int parent = 0;
    int left_child = 0;
    int right_child = 0;
} nodes[10002];

int parent_nodes[10000] = {0};

int count_tree_nodes(int index)
{
    int count=0;
    if (index == 0)
        return 0;
    if (nodes[index].left_child != 0 && nodes[index].right_child != 0)
        return count_tree_nodes(nodes[index].left_child) + count_tree_nodes(nodes[index].right_child) + 1;
    else if (nodes[index].left_child != 0)
        return count_tree_nodes(nodes[index].left_child) + 1;
    else if (nodes[index].right_child != 0)
        return count_tree_nodes(nodes[index].right_child) + 1;
    else
        return 1;
}

int main(void)
{
    int test_case, total_node_number, total_edge_number, target_node1, target_node2;
    cin >> test_case;
    int parent, child;
    for(int cases=1; cases<=test_case; cases++)
    {
        cin >> total_node_number >> total_edge_number >> target_node1 >> target_node2;
        // initialize tree
        for(int i=0; i<10002; i++)
        {
            nodes[i].parent = 0; 
            nodes[i].left_child = 0;
            nodes[i].right_child = 0;
        }
        // Build the tree of nodes
        for(int i=total_edge_number; i!=0; i--)
        {
            cin >> parent >> child;
            if (nodes[parent].left_child == 0)
                nodes[parent].left_child = child;
            else
                nodes[parent].right_child = child;
            nodes[child].parent = parent;
        }
        // Find same ancestor of two nodes
        // For first node
        memset(parent_nodes, 0, sizeof(parent_nodes));
        parent_nodes[0] = target_node1;
        int first_node_parent_num=1;
        while (nodes[target_node1].parent != 0)
        {
            parent_nodes[first_node_parent_num] = nodes[target_node1].parent;
            target_node1 = nodes[target_node1].parent;
            first_node_parent_num += 1;
        }
        // For second node
        int index=0;
        int common_ancestor_index=0;
        while (target_node2 != 0)
        {
            for(int i=0; i<first_node_parent_num; i++)
            {
                if(target_node2 == parent_nodes[i])
                {
                    common_ancestor_index = parent_nodes[i];
                    break;
                }
            }
            if (common_ancestor_index)
                break;
            target_node2 = nodes[target_node2].parent;
            index += 1;
        }
        // count the sub-tree nodes
        int count = count_tree_nodes(common_ancestor_index);
        cout << '#' << cases << ' ' << common_ancestor_index << ' ' << count << '\n';
    }
    return 0;
}