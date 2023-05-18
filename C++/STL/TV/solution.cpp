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
		// 시작 시간에 모든 인원이 방송들 듣고 있어야 한다.
		// 하단 코드가 pq중에 단 하나만 새로 들어온 애랑 비교하니까, queue에 남아 있는 애들 중 가장 최악의 경우의 수를 그 단 한번에 비교에 사용해야 하는 것.
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
