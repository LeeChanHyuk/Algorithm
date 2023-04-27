#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* head;
int total_node = 0;

void get_node(int data)
{
    if (total_node == 0)
    {
        Node* newNode = new Node();
        newNode->data = data;
        head = newNode;
    }
    else
    {
        Node* currentNode = head;
        while (currentNode->next != nullptr) currentNode = currentNode->next;
        Node* newNode = new Node();
        newNode->data = data;
        currentNode->next = newNode;
        newNode->prev = currentNode;
    }
    total_node += 1;
}

void add_node_num(int data, int num)
{
    if (total_node < num)
    {
        Node* currentNode = head;
        Node* newNode = new Node();
        for(int i=1; i<num; i++)
        {
            currentNode = currentNode->next;
        }
        newNode->prev = currentNode->prev;
        newNode->next = currentNode;
        currentNode->prev->next = newNode;
        currentNode->next->prev = newNode;
    }
    else
    {
        printf("Please enter another number\n");
        return;
    }
}

int total_node_count(void)
{
    printf("total count is %d\n", total_node);
}

int main(void)
{
    
    return 0;
}