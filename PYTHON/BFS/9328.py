from sys import stdin
from collections import deque

test_case = int(stdin.readline().strip())
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(queue, vias, keys, col, row, paper, unopened_door, unopened_door_position):
	while len(queue) > 0:
		origin_y, origin_x = queue.popleft()
		for i in range(4):
			dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
			if dest_y >= row or dest_y < 0 or dest_x >= col or dest_x < 0:
				continue
			if vias[dest_y][dest_x] > 0:
				continue
			if board[dest_y][dest_x] == '*':
				continue
			if board[dest_y][dest_x].isupper() and board[dest_y][dest_x].lower() not in keys:
				unopened_door.append(board[dest_y][dest_x])
				unopened_door_position.append([vias[origin_y][origin_x]+1, [dest_y, dest_x]])
				continue
			if board[dest_y][dest_x].islower():
				keys.append(board[dest_y][dest_x])
				while keys[-1].upper() in unopened_door:
					target_index = unopened_door.index(keys[-1].upper())
					via, [y, x] = unopened_door_position[target_index]
					unopened_door.pop(target_index)
					unopened_door_position.pop(target_index)
					vias[y][x] = via
					queue.append([y, x])
			if board[dest_y][dest_x] == '$':
				paper += 1
			vias[dest_y][dest_x] = vias[origin_y][origin_x] + 1
			queue.append([dest_y, dest_x])
	return paper

for case in range(test_case):
	board = []
	keys = []
	vias = []
	queue = deque()
	row, col = map(int, stdin.readline().strip().split(' '))
	for i in range(row):
		board.append(stdin.readline().strip())
		vias.append([0] * col)
	key = stdin.readline().strip()
	for i in range(len(key)):
		keys.append(key[i])
	unopened_door = []
	unopened_door_position = []
	
	paper_num = 0
	for i in range(col):
		if vias[0][i] == 0:
			if board[0][i] == '.' or board[0][i].lower() in keys:
				queue.append([0, i])
				vias[0][i] = 1
			elif board[0][i] == '$':
				queue.append([0, i])
				paper_num += 1
				vias[0][i] = 1
			elif board[0][i].islower():
				queue.append([0, i])
				vias[0][i] = 1
				keys.append(board[0][i])
				while board[0][i].upper() in unopened_door:
					target_index = unopened_door.index(board[0][i].upper())
					via, [y, x] = unopened_door_position[target_index]
					unopened_door.pop(target_index)
					unopened_door_position.pop(target_index)
					vias[y][x] = via
					queue.append([y, x])
			elif board[0][i].isupper():
				if board[0][i].lower() in keys:
					queue.append([0, i])
					vias[0][i] = 1
				else:
					unopened_door.append(board[0][i])
					unopened_door_position.append([1, [0, i]])



		if vias[row-1][i] == 0:
			if board[row-1][i] == '.' or board[row-1][i].lower() in keys:
				queue.append([row-1, i])
				vias[row-1][i] = 1
			elif board[row-1][i] == '$':
				queue.append([row-1, i])
				paper_num += 1
				vias[row-1][i] = 1
			elif board[row-1][i].islower():
				queue.append([row-1, i])
				vias[row-1][i] = 1
				keys.append(board[row-1][i])
				while board[row-1][i].upper() in unopened_door:
					target_index = unopened_door.index(board[row-1][i].upper())
					via, [y, x] = unopened_door_position[target_index]
					unopened_door.pop(target_index)
					unopened_door_position.pop(target_index)
					vias[y][x] = via
					queue.append([y, x])
			elif board[row-1][i].isupper():
				if board[row-1][i].lower() in keys:
					queue.append([0, i])
					vias[0][i] = 1
				else:
					unopened_door.append(board[row-1][i])
					unopened_door_position.append([1, [row-1, i]])


	for i in range(row):
		if vias[i][0] == 0:
			if board[i][0] == '.' or board[i][0].lower() in keys:
				queue.append([i, 0])
				vias[i][0] = 1
			elif board[i][0] == '$':
				queue.append([i, 0])
				paper_num += 1
				vias[i][0] = 1
			elif board[i][0].islower():
				queue.append([i, 0])
				keys.append(board[i][0])
				vias[i][0] = 1
				while board[i][0].upper() in unopened_door:
					target_index = unopened_door.index(board[i][0].upper())
					via, [y, x] = unopened_door_position[target_index]
					unopened_door.pop(target_index)
					unopened_door_position.pop(target_index)
					vias[y][x] = via
					queue.append([y, x])
			elif board[i][0].isupper():
				if board[i][0].lower() in keys:
					queue.append([i, 0])
					vias[i][0] = 1
				else:
					unopened_door.append(board[i][0])
					unopened_door_position.append([1, [i, 0]])
		if vias[i][col-1] == 0:
			if board[i][col-1] == '.' or board[i][col-1].lower() in keys:
				queue.append([i, col-1])
				vias[i][col-1] = 1
			elif board[i][col-1] == '$':
				queue.append([i, col-1])
				paper_num += 1
				vias[i][col-1] = 1
			elif board[i][col-1].islower():
				queue.append([i, col-1])
				vias[i][col-1] = 1
				keys.append(board[i][col-1])
				while board[i][col-1].upper() in unopened_door:
					target_index = unopened_door.index(board[i][col-1].upper())
					via, [y, x] = unopened_door_position[target_index]
					unopened_door.pop(target_index)
					unopened_door_position.pop(target_index)
					vias[y][x] = via
					queue.append([y, x])
			elif board[i][col-1].isupper():
				if board[i][col-1].lower() in keys:
					queue.append([i, col-1])
					vias[i][col-1] = 1
				else:
					unopened_door.append(board[i][col-1])
					unopened_door_position.append([1, [i, col-1]])


	paper_num = bfs(queue, vias, keys, col, row, paper_num, unopened_door, unopened_door_position)
	print(paper_num)

	
