#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

struct Node {
	int data;
	Node* prev;
	Node* next;
};

int nodeCnt;
Node* head;

Node* getNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->next = nullptr;
	node->prev = nullptr;
	return node;
}

void init()
{
	nodeCnt = 0;
}

void addNode2Head(int data) 
{
	Node* newNode = getNode(data);
	if (nodeCnt > 0)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else
		head = newNode;
	nodeCnt += 1;
}

void addNode2Tail(int data) 
{
	Node* currentNode = head;
	Node* newNode = getNode(data);
	if (nodeCnt > 0)
	{
		while (currentNode->next != nullptr) currentNode = currentNode->next;
		currentNode->next = newNode;
		newNode->prev = currentNode;
	}
	else
		head = newNode;
	nodeCnt += 1;
}

void addNode2Num(int data, int num) 
{
	Node* currentNode = head;
	Node* newNode = getNode(data);
	for(int i=1; i<num-1; i++)
		currentNode = currentNode->next;
	if (num == 1)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (nodeCnt > 0)
	{
		newNode->next = currentNode->next;
		newNode->prev = currentNode;
		if (currentNode->next != nullptr)
			currentNode->next->prev = newNode;
		currentNode->next = newNode;
	}
	else
		head = newNode;
	nodeCnt += 1;
}

int findNode(int data) 
{
	Node* currentNode = head;
	int order = 1;
	for(int i=0; i<nodeCnt; i++)
	{
		if (currentNode->data == data)
			return order;
		else
		{
			currentNode = currentNode->next;
			order += 1;
		}
	}
	return 0;
}

void removeNode(int data) 
{
	Node* currentNode = head;
	int count = 0;
	if (data == head->data)
	{
		head = head->next;
		head->prev = nullptr;
		currentNode->data = 0;
		currentNode->next = nullptr;
		nodeCnt -= 1;
	}
	else
	{
		while (currentNode->next != nullptr)
		{
			if (data == currentNode->next->data)
			{
				currentNode->next->data = 0;
				if (currentNode->next->next != nullptr)
					currentNode->next->next->prev = currentNode;
				currentNode->next = currentNode->next->next;
				nodeCnt -= 1;
				break;
			}
			else
				currentNode = currentNode->next;
		}
	}
}

int getList(int output[MAX_NODE]) 
{
	Node* currentNode = head;
	for(int i=0; i<nodeCnt; i++)
	{
		output[i] = currentNode->data;
		currentNode = currentNode->next;
	}
	return nodeCnt;
}

int getReversedList(int output[MAX_NODE]) 
{
	Node* currentNode = head;
	while (currentNode->next != nullptr) currentNode = currentNode->next;
	for(int i=0; i<nodeCnt; i++)
	{
		output[i] = currentNode->data;
		currentNode = currentNode->prev;
	}
	return nodeCnt;
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("dll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}