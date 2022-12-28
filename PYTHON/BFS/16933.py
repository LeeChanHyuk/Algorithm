from sys import stdin
from collections import deque

N, M, K = map(int, stdin.readline().strip().split(' '))

board = []
for i in range(N):
	board.append(stdin.readline().strip())

via = [[[-1] * (K + 1) for j in range(M)] for k in range(N)]
dx = [0, 1, 0, -1, 0]
dy = [1, 0, -1, 0, 0]

def state_change(state):
	if state == 0:
		return 1
	else:
		return 0

def bfs():
	queue = deque()
	state = 1
	queue.append([0, 0, 0, state])
	via[0][0][0] = 1
	success = False
	result = 0
	block = False
	while len(queue) > 0:
		origin_y, origin_x, origin_k, state = queue.popleft()
		if origin_x == M-1 and origin_y == N-1:
			success = True
			result = via[origin_y][origin_x][origin_k]
			break
		for i in range(5):
			dest_x, dest_y = origin_x + dx[i], origin_y + dy[i]
			if dest_x < 0 or dest_x >= M or dest_y < 0 or dest_y >= N:
				continue
			if via[dest_y][dest_x][origin_k] != -1:
				continue
			if board[dest_y][dest_x] == '1':
				if origin_k < K and via[dest_y][dest_x][origin_k+1] == -1 and state:
					queue.append([dest_y, dest_x, origin_k + 1, state_change(state)])
					via[dest_y][dest_x][origin_k+1] = via[origin_y][origin_x][origin_k] + 1
				elif origin_k < K and via[dest_y][dest_x][origin_k+1] == -1:
					block = True
				continue
			if i == 4 and block:
				queue.append([origin_y, origin_x, origin_k, state_change(state)])
				via[origin_y][origin_x][origin_k] = via[origin_y][origin_x][origin_k] + 1
			queue.append([dest_y, dest_x, origin_k, state_change(state)])
			via[dest_y][dest_x][origin_k] = via[origin_y][origin_x][origin_k] + 1
	if success:
		print(result)
	else:
		print(-1)
bfs()


