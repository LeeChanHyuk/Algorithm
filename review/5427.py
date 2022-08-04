from sys import stdin
from collections import deque
Testcase = int(stdin.readline().strip())
dx = [1, 0 ,-1 ,0]
dy = [0, -1, 0, 1]
fire = deque()
dog = deque()
for case in range(Testcase):
	w, h = map(int, stdin.readline().strip().split(' '))
	dog_via = [[0] * w for i in range(h)]
	fire_via = [[0] * w for i in range(h)]
	board = []
	fire.clear()
	dog.clear()
	step = 1
	success = 0
	for i in range(h):
		line = stdin.readline().strip()
		board.append(line)
		for j in range(w):
			if line[j] == '@':
				dog.append((i, j, 1))
				dog_via[i][j] = 1
			elif line[j] == '*':
				fire.append((i, j, 1))
				fire_via[i][j] = 1
	while dog:
		while fire and step == fire[0][2]:
			f_y, f_x, cnt = fire.popleft()
			for i in range(4):
				nx, ny = f_x + dx[i], f_y + dy[i]
				if 0 <= nx < w and 0 <= ny < h:
					if fire_via[ny][nx] == 0 or fire_via[ny][nx] > fire_via[f_y][f_x] + 1 and board[ny][nx] != '#':
						fire_via[ny][nx] = fire_via[f_y][f_x] + 1
						fire.append((ny, nx, cnt+1))

		while dog and step == dog[0][2] and success == 0:
			d_y, d_x, cnt = dog.popleft()
			for i in range(4):
				nx, ny = d_x + dx[i], d_y + dy[i]
				if 0 <= nx < w and 0 <= ny < h:
					if dog_via[ny][nx] == 0 or dog_via[ny][nx] > dog_via[d_y][d_x] + 1 and board[ny][nx] == '.':
						if fire_via[ny][nx] == 0 or fire_via[ny][nx] > dog_via[d_y][d_x] + 1:
							dog_via[ny][nx] = dog_via[d_y][d_x] + 1
							dog.append((ny, nx, cnt+1))
				elif success == 0:
					success = dog_via[d_y][d_x]
					break
		if success:
			break
		step += 1
	if success:
		print(success)
	else:
		print('IMPOSSIBLE')