from sys import stdin
from collections import deque
Testcase = int(stdin.readline().strip())
dx = [1, 0 ,-1 ,0]
dy = [0, -1, 0, 1]
for case in range(Testcase):
	w, h = map(int, stdin.readline().strip().split(' '))
	board = []
	dog_via = [[0 for j in range(w)] for i in range(h)]
	fire_via = [[0 for j in range(w)] for i in range(h)]
	fire = deque()
	dog = deque()
	success = 0
	for i in range(h):
		line = stdin.readline().strip()
		board.append(line)
		for j in range(w):
			if line[j] == '@':
				dog.append((i, j))
				dog_via[i][j] = 1
			elif line[j] == '*':
				fire.append((i, j))
				fire_via[i][j] = 1
	
	while fire:
		y, x = fire.popleft()
		for i in range(4):
			nx, ny = x + dx[i], y + dy[i]
			if 0 <= nx < w and 0 <= ny < h:
				if fire_via[ny][nx] == 0 and board[ny][nx] != '#':
					fire_via[ny][nx] = fire_via[y][x] + 1
					fire.append((ny, nx))
	while dog and success == 0:
		y, x = dog.popleft()
		if x == 0 or x == w-1 or y==0 or y == h-1:
			success = dog_via[y][x]
			continue
		for i in range(4):
			nx, ny = x + dx[i], y + dy[i]
			if 0 <= nx < w and 0 <= ny < h:
				if dog_via[ny][nx] == 0 and board[ny][nx] != '#':
					if fire_via[ny][nx] == 0 or fire_via[ny][nx] > dog_via[y][x] + 1:
						dog_via[ny][nx] = dog_via[y][x] + 1
						dog.append((ny, nx))
			elif success == 0:
				success = dog_via[y][x]
				break
	if success:
		print(success)
	else:
		print('IMPOSSIBLE')