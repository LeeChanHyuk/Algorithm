from sys import stdin
from collections import deque

N, M, P = map(int, stdin.readline().strip().split(' '))
P_list = list(map(int, stdin.readline().strip().split(' ')))
deque_list = []
for num in range(len(P_list)):
	temp_deque = deque()
	deque_list.append(temp_deque)
board = []
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
via = [[-1] * M for i in range(N)]
for i in range(N):
	line = stdin.readline().strip()
	board.append(line)
	for j in range(M):
		if line[j] == '#' or line[j] == '.':
			continue
		num = int(line[j])
		deque_list[num-1].append([i, j])
		via[i][j] = 1

def bfs(deque_list, P_list):
	count = [0] * len(deque_list)
	origin_list = deque()
	for index, temp_deque in enumerate(deque_list):
		count[index] += len(temp_deque)
	while 1:
		finish = True
		if sum(count) == M*N:
			break
		for i in range(len(deque_list)):
			if len(deque_list[i]) > 0:
				finish = False
		if finish:
			break
		for index, player in enumerate(deque_list):
			origin_list.clear()
			movable_range = P_list[index]
			while len(player) > 0:
				origin_y, origin_x = player.popleft()
				origin_list.append([origin_y, origin_x])
			while movable_range > 0 and sum(count) < N * M and len(origin_list) > 0:
				movable_range -= 1
				origin_list_len = len(origin_list)
				for i in range(origin_list_len):
					origin_y, origin_x = origin_list[i]
					for i in range(4):
						dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
						if dest_y < 0 or dest_y >= N or dest_x < 0 or dest_x >= M or board[dest_y][dest_x] != '.' or via[dest_y][dest_x] != -1:
							continue
						via[dest_y][dest_x] = 1
						origin_list.append([dest_y, dest_x])
						count[index] += 1
				for i in range(origin_list_len):
					a, b = origin_list.popleft()
			while len(origin_list) > 0:
				player.append(origin_list.popleft())
	for i in range(len(count)):
		print(count[i], end=' ')
bfs(deque_list, P_list)




