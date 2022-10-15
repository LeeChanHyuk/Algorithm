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

def dfs(current_node):
    global node, via1, V
    via1[current_node-1] = 1
    print(current_node, end=' ')
    for i in range(len(node[current_node-1])):
        if via1[node[current_node-1][i]-1]:
            continue
        dfs(node[current_node-1][i])


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
dfs(V)
print()
bfs()





