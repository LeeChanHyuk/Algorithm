#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* head;

Node* getNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
}

void addNode(int data)
{
    
}

int main(void)
{
    int data;
    scanf("%d", &data);
    head = getNode(data);

    return 0;
}