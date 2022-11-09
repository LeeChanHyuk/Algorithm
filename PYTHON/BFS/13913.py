from sys import stdin
from collections import deque

via = [0] * 100001
record = [-1] * 100001

dx = [1, -1]

N, K = map(int, stdin.readline().strip().split(' '))
via[N] = 1

def bfs():
	queue = deque()
	queue.append(N)
	success = False
	while len(queue) > 0 and success is False:
		origin_x = queue.popleft()
		current_via = via[origin_x]
		for i in range(3):
			if i < 2:
				dest_x = origin_x + dx[i]
			else:
				dest_x = origin_x * 2
			if dest_x > 100000 or dest_x < 0:
				continue
			if via[dest_x] > 0:
				continue
			if dest_x == K:
				via[dest_x] = current_via + 1
				record[dest_x] = origin_x
				success = True
				break
			via[dest_x] = current_via + 1
			record[dest_x] = origin_x
			queue.append(dest_x)
bfs()
print(via[K] - 1)
record_list = [K]
current_index = K
while 1:
	if record[current_index] == -1:
		break
	record_list.append(record[current_index])
	current_index = record[current_index]
record_list.reverse()
for i in range(len(record_list)):
	print(record_list[i], end=' ')


