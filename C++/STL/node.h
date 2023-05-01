#ifndef NODE_H
#define NODE_H

int getNode(int data);

struct Node{
	int start_col;
	Node* nextNode;
	Node* prevNode;
};
extern Node* head;

#endif // !1
