#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

struct Node {
	int data;
	Node* next;
};

int nodeCnt;
Node* head;

Node* getNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->next = nullptr;
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
		head = newNode;
	}
	else if (nodeCnt > 0)
	{
		newNode->next = currentNode->next;
		currentNode->next = newNode;
	}
	else
		head = newNode;
	nodeCnt += 1;
}

void removeNode(int data) 
{
	Node* currentNode = head;
	int count = 0;
	if (data == head->data)
	{
		head = head->next;
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

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
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
	//freopen("sll_input.txt", "r", stdin);

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