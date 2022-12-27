from sys import stdin
from collections import deque

N, M, K = map(int, stdin.readline().strip().split(' '))
board = []
via = [[[-1] * (K + 1) for x in range(M)] for y in range(N)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for i in range(N):
	board.append(stdin.readline().strip())

def bfs():
	queue = deque()
	queue.append([0, 0, 0])
	via[0][0][0] = 0
	success = False
	result = 0
	while len(queue) > 0 and success == False:
		origin_x, origin_y, origin_k = queue.popleft()
		if origin_y == N-1 and origin_x == M-1:
			success = True
			result = via[origin_y][origin_x][origin_k] + 1
			break
		for i in range(4):
			dest_x, dest_y = origin_x + dx[i], origin_y + dy[i]
			if dest_x < 0 or dest_x >= M or dest_y < 0 or dest_y >= N:
				continue
			if via[dest_y][dest_x][origin_k] != -1:
				continue
			if board[dest_y][dest_x] == '1':
				if origin_k < K and via[dest_y][dest_x][origin_k+1] == -1:
					via[dest_y][dest_x][origin_k+1] = via[origin_y][origin_x][origin_k] + 1
					queue.append([dest_x, dest_y, origin_k + 1])
				continue
			via[dest_y][dest_x][origin_k] = via[origin_y][origin_x][origin_k] + 1
			queue.append([dest_x, dest_y, origin_k])
	if success:
		print(result)
	else:
		print(-1)
bfs()