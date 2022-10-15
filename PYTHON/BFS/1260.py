from sys import stdin
from collections import deque

N, M, V = map(int, stdin.readline().strip().split(' '))
node = []
for i in range(1,N+1):
    node.append([])
via1 = [0] * len(node)
via2 = [0] * len(node)
for i in range(M):
    start_node, end_node = map(int, stdin.readline().strip().split(' '))
    node[start_node-1].append(end_node)
    node[end_node-1].append(start_node)
for i in range(N):
    node[i].sort()
    node[i][:] = node[i][::-1]

def dfs():
    global node, via1, V
    stack = []
    via1[V-1] = 1
    stack.append(V)
    print(V, end = ' ')
    while len(stack) > 0:
        start_node = stack.pop()
        for i in range(len(node[start_node-1])):
            current_node = node[start_node-1][i]
            if via1[current_node-1] > 0:
                continue
            via1[current_node-1] = 1
            print(current_node, end=' ')
            stack.append(current_node)
            break
    print()

def bfs():
    global node, via2, V
    queue = deque()
    queue.append(V)
    via2[V-1] = 1
    print(V, end=' ')
    while len(queue) > 0:
        start_node = queue.popleft()
        for i in range(len(node[start_node-1])):
            current_node = node[start_node-1][i]
            if via2[current_node-1] > 0:
                continue
            via2[current_node-1] = 1
            print(current_node, end=' ')
            queue.append(current_node)
dfs()
for i in range(N):
    node[i].sort()
bfs()





