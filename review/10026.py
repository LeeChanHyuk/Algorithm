from sys import stdin
N = int(stdin.readline().strip())
RGB_board = [[j for j in range(N)] for i in range(N)]
RB_board = [[j for j in range(N)] for i in range(N)]
RGB_via = [[0 for j in range(N)] for i in range(N)]
RB_via = [[0 for j in range(N)] for i in range(N)]
red = []
blue = [] # green is not needed
queue = []
red_num = 0
blue_num = 0
red_green_num = 0
for i in range(N):
	line = stdin.readline().strip()
	for j in range(N):
		if line[j] == 'G':
			RGB_board[i][j] = 'G'
			RB_board[i][j] = 'R'
			red.append((i, j))
		elif line[j] == 'B':
			RGB_board[i][j] = line[j]
			RB_board[i][j] = line[j]
			blue.append((i, j))
		else: # red
			RGB_board[i][j] = line[j]
			RB_board[i][j] = line[j]
			red.append((i, j))

for index in range(len(blue)):
	i, j = blue[index]
	if RGB_via[i][j] == 1:
		continue
	blue_num += 1
	RGB_via[i][j] = 1
	RB_via[i][j] = 1
	queue.append((i, j))
	while len(queue) > 0:
		i, j = queue.pop(0)
		if j+1<N and RGB_board[i][j+1] == 'B' and RGB_via[i][j+1] == 0:
			RGB_via[i][j+1] = 1
			RB_via[i][j+1] = 1
			queue.append((i, j+1))
		if i+1<N and RGB_board[i+1][j] == 'B' and RGB_via[i+1][j] == 0:
			RGB_via[i+1][j] = 1
			RB_via[i+1][j] = 1
			queue.append((i+1, j))
		if i-1>= 0 and RGB_board[i-1][j] == 'B' and RGB_via[i-1][j] == 0:
			RGB_via[i-1][j] = 1
			RB_via[i-1][j] = 1
			queue.append((i-1, j))
		if j-1>=0 and RGB_board[i][j-1] == 'B' and RGB_via[i][j-1] == 0:
			RGB_via[i][j-1] = 1
			RB_via[i][j-1] = 1
			queue.append((i, j-1))

for index in range(len(red)):
	i, j = red[index]
	if RGB_via[i][j] == 1:
		continue
	red_green_num += 1
	RGB_via[i][j] = 1
	queue.append((i, j))
	while len(queue) > 0:
		i, j = queue.pop(0)
		if j+1<N and RGB_board[i][j+1] == RGB_board[i][j] and RGB_via[i][j+1] == 0:
			RGB_via[i][j+1] = 1
			queue.append((i, j+1))
		if i+1<N and RGB_board[i+1][j] ==  RGB_board[i][j] and RGB_via[i+1][j] == 0:
			RGB_via[i+1][j] = 1
			queue.append((i+1, j))
		if i-1>= 0 and RGB_board[i-1][j] == RGB_board[i][j] and RGB_via[i-1][j] == 0:
			RGB_via[i-1][j] = 1
			queue.append((i-1, j))
		if j-1>=0 and RGB_board[i][j-1] ==  RGB_board[i][j] and RGB_via[i][j-1] == 0:
			RGB_via[i][j-1] = 1
			queue.append((i, j-1))

for index in range(len(red)):
	i, j = red[index]
	if RB_via[i][j] == 1:
		continue
	red_num += 1
	RB_via[i][j] = 1
	queue.append((i, j))
	while len(queue) > 0:
		i, j = queue.pop(0)
		if j+1<N and RB_board[i][j+1] == RB_board[i][j] and RB_via[i][j+1] == 0:
			RB_via[i][j+1] = 1
			queue.append((i, j+1))
		if i+1<N and RB_board[i+1][j] ==  RB_board[i][j] and RB_via[i+1][j] == 0:
			RB_via[i+1][j] = 1
			queue.append((i+1, j))
		if i-1>= 0 and RB_board[i-1][j] == RB_board[i][j] and RB_via[i-1][j] == 0:
			RB_via[i-1][j] = 1
			queue.append((i-1, j))
		if j-1>=0 and RB_board[i][j-1] ==  RB_board[i][j] and RB_via[i][j-1] == 0:
			RB_via[i][j-1] = 1
			queue.append((i, j-1))
print(blue_num + red_green_num, end = ' ')
print(blue_num + red_num)