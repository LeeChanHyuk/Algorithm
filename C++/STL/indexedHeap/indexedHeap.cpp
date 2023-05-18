#include <iostream>

using namespace std;

#define MAX_HEAP 1
#define MIN_HEAP 0

int heap[1000];
int heap_num = 0;

void swap(int child, int parent)
{
	int temp = heap[child];
	heap[child] = heap[parent];
	heap[parent] = temp;
}


void updateAddHeap(int index, int HEAP_SORT)
{
	if (index == 1)
		return;
	if (HEAP_SORT == MAX_HEAP)
	{
		if (heap[index] > heap[index / 2])
		{
			swap(index, index / 2);
			updateAddHeap(index / 2, HEAP_SORT);
		}
	}
	else if (HEAP_SORT == MIN_HEAP)
	{
		if (heap[index] < heap[index / 2])
		{
			swap(index, index / 2);
			updateAddHeap(index / 2, HEAP_SORT);
		}
	}
}

void updatePopHeap(int index, int HEAP_SORT)
{
	if (index > heap_num)
		return;
	if (HEAP_SORT == MAX_HEAP)
	{
		if (heap[index * 2] >= heap[index * 2 + 1] && heap[index] < heap[index * 2])
		{
			swap(index, index * 2);
			updatePopHeap(index * 2, HEAP_SORT);
		}
		else if (heap[index * 2] < heap[index * 2 + 1] && heap[index] < heap[index * 2 + 1])
		{
			swap(index, index * 2 + 1);
			updatePopHeap(index * 2 + 1, HEAP_SORT);
		}
	}
	else
	{
		if (heap[index * 2] <= heap[index * 2 + 1] && heap[index] > heap[index * 2])
		{
			swap(index, index * 2);
			updatePopHeap(index * 2, HEAP_SORT);
		}
		else if (heap[index * 2] > heap[index * 2 + 1] && heap[index] > heap[index * 2 + 1])
		{
			swap(index, index * 2 + 1);
			updatePopHeap(index * 2 + 1, HEAP_SORT);
		}
	}
}

void addHeap(int val)
{
	heap[++heap_num] = val;
	updateAddHeap(heap_num, MAX_HEAP); // from leaf node
}

int popHeap()
{
	int popVal = heap[1];
	heap[1] = heap[heap_num--];
	updatePopHeap(1, MAX_HEAP); // from root node
	return popVal;
}

void visualizeHeap()
{
	cout << '\n';
	int jump = 2;
	for (int i = 1; i <= heap_num; i++)
	{
		if (i == jump)
		{
			cout << '\n';
			jump *= 2;
		}
		cout << heap[i] << ' ';
	}
}

int main(void)
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		addHeap(num);
		visualizeHeap();
	}
	return 0;
}