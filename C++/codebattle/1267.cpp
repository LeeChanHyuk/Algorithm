#include <iostream>
#include <string.h>
#include <list>
#include <queue>

using namespace std;

struct{
    list<int> child;
    list<int> parent;
} nodes[1002];

int main(void)
{

    int total_node_num, total_edge_num, parent_node, child_node;
    for(int test_case=1; test_case<=10; test_case++)
    {
        for(int i=0; i<1002; i++)
        {
            nodes[i].child.clear();
            nodes[i].parent.clear();
        }
        queue<int> work_waiting_list;
        cin >> total_node_num >> total_edge_num;
        for(int edge=0; edge<total_edge_num; edge++)
        {
            cin >> parent_node >> child_node;
            nodes[parent_node].child.push_back(child_node);
            nodes[child_node].parent.push_back(parent_node);
        }
        // select the node not having any parent node.
        for(int i=1; i<total_node_num; i++)
            if(nodes[i].parent.empty())
                work_waiting_list.push(i);
        // working process
        cout << "#" << test_case << ' ';
        while(!work_waiting_list.empty())
        {
            int working_index = work_waiting_list.front();
            work_waiting_list.pop();
            cout << working_index << ' ';
            // for all child of the selected node
            list<int>::iterator iter;
            for(iter = nodes[working_index].child.begin(); iter!= nodes[working_index].child.end(); iter++){
                nodes[*iter].parent.remove(working_index);
                if (nodes[*iter].parent.empty())
                    work_waiting_list.push(*iter);
            }    
        }
        cout << '\n';
    }
    return 0;
}