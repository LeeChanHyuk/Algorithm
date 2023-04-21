#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node {
    int order;
	int size;
    Node* prev;
    Node* next;
};
 
Node* getNode(int size, int order){
    Node* node = new Node();
    node->order = order;
	node->size = size;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

struct compare{
bool operator()(Node*&a, Node*&b) {
              if (a->size == b->size) {
                  return a->order > b->order;
              }
              else {
                  return a->size < b->size;
              }
          }
};

priority_queue<Node*,vector<Node*>,compare> pqueue; // (size, order)
long long userID [100000001] = {0};
Node* nodes[100000001];
int seat_size = 0;
int seat_order = 0;
int total_length = 0;
int total_cnt = 0;
int mid = 0;
int new_seat_size = 0;

void init(int N) {
	total_length = N;
	Node* newNode = getNode(N, 1);
	nodes[1] = newNode;
	nodes[N] = newNode;
	pqueue.push(newNode);
	return;
}

int arrive(int mId) {
	mId %= 10;
	// biggest black seat array
	seat_size = pqueue.top()->size;
	seat_order = pqueue.top()->order;

	// arrive sequence
	if (seat_order == 1)
	{
		total_cnt += 1;
		pqueue.pop();
		Node* newNode = getNode(seat_size-1, seat_order+1);
		pqueue.push(newNode);

		// seat - node connection
		nodes[1] = nullptr;
		nodes[2] = newNode;
		nodes[seat_size] = newNode;
		userID[mId] = 1;
		return 1;
	}
	else if (seat_order + seat_size - 1 == total_length)
	{
		total_cnt += 1;
		pqueue.pop();
		Node* newNode = getNode(seat_size-1, seat_order);
		pqueue.push(newNode);
		
		// seat - node connection
		nodes[total_length] = nullptr;
		nodes[seat_order] = newNode;
		nodes[seat_order + seat_size - 2] = newNode;
		userID[mId] = total_length;
		return seat_order + seat_size - 1;
	}
	else
	{
		if(seat_size % 2 == 1)
		{
			mid = seat_order + (seat_size / 2);
			new_seat_size = seat_size / 2;
			total_cnt += 1;
			if(seat_size != 1)
			{
				pqueue.pop();
				Node* newNode1 = getNode(new_seat_size, seat_order);
				Node* newNode2 = getNode(new_seat_size, mid+1);
				pqueue.push(newNode1);
				nodes[seat_order] = newNode1;
				nodes[seat_order + new_seat_size - 1] = newNode1;
				pqueue.push(newNode2);
				nodes[mid+1] = newNode2;
				nodes[mid+1 + new_seat_size - 1] = newNode2;
			}
		}
		else
		{
			mid = seat_order + (seat_size / 2) - 1;
			new_seat_size = (seat_size / 2) - 1;
			total_cnt += 1;
			if (seat_size != 2)
			{
				pqueue.pop();
				Node* newNode1 = getNode(new_seat_size, seat_order);
				Node* newNode2 = getNode(new_seat_size+1, mid+1);
				pqueue.push(newNode1);
				nodes[seat_order] = newNode1;
				nodes[seat_order + new_seat_size - 1] = newNode1;
				pqueue.push(newNode2);
				nodes[mid+1] = newNode2;
				nodes[mid + 1+ new_seat_size + 1 - 1] = newNode2;
			}
			else
			{
				pqueue.pop();
				Node* newNode = getNode(1, seat_order + 1);
				pqueue.push(newNode);
				nodes[seat_order+1] = newNode;
			}
		}
		userID[mId] = mid;
		return mid;
	}
	return 0;
}

int leave(int mId) {
	mId %= 10;
	int seat = userID[mId];
	if (seat == 1 || (nodes[seat-1] == nullptr && nodes[seat+1] != nullptr))
		if (nodes[seat+1] != nullptr)
		{
			nodes[seat+1]->size += 1;
			nodes[seat+1]->order -= 1;
			nodes[seat] = nodes[seat+1];
			nodes[seat+1] = nullptr;
		}
	else if (seat == total_length || (nodes[seat+1] == nullptr && nodes[seat-1] != nullptr))
		if (nodes[seat-1] != nullptr)
		{
			nodes[seat-1]->size += 1;
			nodes[seat] = nodes[seat-1];
			nodes[seat-1] = nullptr;
		}
	else
	{
		int left_seat = nodes[seat-1]->order;
		nodes[seat-1] = nullptr;
		int right_seat = nodes[seat+1]->order + nodes[seat+1]->size - 1;
		nodes[seat+1] = nullptr;
		Node* newNode = getNode((right_seat-left_seat+1), left_seat);
		nodes[left_seat] = newNode;
		nodes[right_seat] = newNode;
	}
	userID[mId] = 0;
	total_cnt -= 1;
	return total_length - total_cnt;
}

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ARRIVE 2
#define CMD_LEAVE 3

static bool run() {
	int q;
	scanf("%d", &q);

	int n, mid;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				init(n);
				okay = true;
				break;
			case CMD_ARRIVE:
				scanf("%d %d", &mid, &ans);
				ret = arrive(mid);
				if (ans != ret)
					okay = false;
				break;
			case CMD_LEAVE:
				scanf("%d %d", &mid, &ans);
				ret = leave(mid);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}