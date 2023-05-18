#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

constexpr int MAX_N = 8000;

struct Node
{
	int start, end;
} NodePool[MAX_N];
int PoolCnt;

struct comparePq
{
	bool operator() (const Node* a, const Node* b)
	const {
		return a->end > b->end;
	}
};

struct compareSet
{
	bool operator() (const Node* a, const Node* b)
	const {
		if (a->start == b->start)
			return a < b;
		return a->start < b->start;
	}
};

set<Node*, compareSet> Schedule;
unordered_map<int, set<Node*>::iterator> Hash;

void init()
{
	PoolCnt = 0;
	Schedule.clear();
	Hash.clear();
}

int add(int mId, int mStart, int mEnd)
{
	auto it = Hash.find(mId);
	Node* node = nullptr;
	if (it != Hash.end())
	{
		node = *it->second;
		Schedule.erase(it->second);
	}
	else
	{
		node = &NodePool[PoolCnt++];
	}
	node->start = mStart;
	node->end = mEnd;
	Hash[mId] = Schedule.insert(node).first;
	return Schedule.size();
}

int remove(int mId)
{
	auto it = Hash.find(mId);
	if (it != Hash.end())
	{
		Schedule.erase(it->second);
		Hash.erase(it);
	}
	return Schedule.size();
}

int announce(int mDuration, int M){
	priority_queue<Node*, vector<Node*>, comparePq> pq;
	//queue<Node*> pq;
	

	for (auto node : Schedule)
	{
		int end = node->start + mDuration - 1;
		pq.push(node);
		// ���� �ð��� ��� �ο��� ��۵� ��� �־�� �Ѵ�.
		// �ϴ� �ڵ尡 pq�߿� �� �ϳ��� ���� ���� �ֶ� ���ϴϱ�, queue�� ���� �ִ� �ֵ� �� ���� �־��� ����� ���� �� �� �ѹ��� �񱳿� ����ؾ� �ϴ� ��.
		while (!pq.empty())
		{
			if (pq.top()->end < end)
				pq.pop();
			else
				break;
		}
		if (pq.size() >= M)
			return node->start;
	}
	return -1;
}
