#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
    int data = NULL;
    Node* prev;
    Node* next;
};

Node* head;
Node* tail;
int node_count = 0;

void add_node_front(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    if (head == nullptr)
        head = newNode;
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    node_count += 1;
}

void add_node_back(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    if (tail == nullptr)
        tail = newNode;
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    node_count += 1;
}

void add_node_num(int data, int num)
{
    Node* newNode = new Node();
    newNode->data = data;
    if (num == 1)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else if (num == node_count+1)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        Node* currentNode = head;
        for(int i=1; i<num-1; i++) currentNode = currentNode->next;
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    }
    node_count += 1;
}

void delete_node_num(int num)
{
    Node* currentNode = head;
    while (currentNode->next != nullptr && currentNode->data != num) currentNode = currentNode->next;
    if (currentNode->data == num)
    {
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
    }
    node_count -= 1;
}

void see_all_node_data()
{
    if (node_count > 0)
    {
        Node* currentNode = head;
        while (currentNode->next != nullptr)
        {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("%d\n", currentNode->data);
    }
}

int main(void)
{
    add_node_front(2);
    see_all_node_data();
    add_node_front(3);
    see_all_node_data();
    add_node_front(4);
    see_all_node_data();
    add_node_front(5);
    see_all_node_data();
    add_node_num(1, 1);
    see_all_node_data();
    add_node_num(10, 3);
    see_all_node_data();
    return 0;
}