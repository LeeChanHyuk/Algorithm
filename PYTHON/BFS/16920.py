from sys import stdin
from collections import deque

N, M, P = map(int, stdin.readline().strip().split(' '))
P_list = list(map(int, stdin.readline().strip().split(' ')))
deque_list = [deque() * len(P_list)]
board = []
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
via = [[[-1] * M] for i in range(N)]
count = [0] * len(P_list)
for i in range(N):
	line = stdin.readline().strip()
	board.append(line)
	for j in range(M):
		if line[j] == '#' or line[j] == '.':
			continue
		num = int(line[j])
		if num in P_list:
			deque_list[num-1].append([i, j])

def bfs(deque_list):
	while 1:
		finish = True
		for i in range(len(P_list)):
			if P_list[i] > 0:
				finish = False
		for index, player in enumerate(deque_list):
			origin_list = []
			if len(player) > 0:
				origin_y, origin_x = player.popleft()
				origin_list.append([origin_y, origin_x])
			for i in range(len(origin_list)):
				origin_y, origin_x = origin_list[i]
				for i in range(4):
					dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
					if dest_y < 0 or dest_y >= N or dest_x < 0 or dest_x >= M or board[dest_y][dest_x] != '.':
						continue
					board[dest_y][dest_x] = str(index + 1)
					player.append([dest_y, dest_x])
	for i in range(N):
		for j in range(M):
			if board[i][j] == '#':
				continue
			num = int(board[i][j])
			count[num-1] += 1
	print(count)
bfs(deque_list)




