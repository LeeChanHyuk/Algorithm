from sys import stdin

N, L = map(int, stdin.readline().strip().split(' '))

def make_diff_board(N, board, diff_board):
	for i in range(N):
		for j in range(1, N):
			diff_board[i][j] = board[i][j] - board[i][j-1]
	return diff_board

board = []
diff_board = []
bridge = []
for i in range(N):
	board.append(list(map(int, stdin.readline().strip().split(' '))))
	diff_board.append([0] * N)
	bridge.append([0] * N)

diff_board = make_diff_board(N, board, diff_board)
success_bridge = 0
for i in range(N):
	fail = False
	for j in range(N):
		if diff_board[i][j] == 0:
			continue
		elif diff_board[i][j] > 0:
			need_length = L * (diff_board[i][j])
			if j-1 < need_length:
				fail = True
				break
			now_length = 0
			for k in range(j-1, j-1-need_length, -1):
				if board[i][k] + 1 == board[i][j] and bridge[i][k] == 0:
					now_length += 1
				else:
					now_length = 0
			if now_length >= need_length:
				for k in range(j-1, j-1-need_length, -1):
					bridge[i][k] = 1
		elif diff_board[i][j] < 0:
			need_length = L * -1 * diff_board[i][j]
			if N-j-1 < need_length:
				fail = True
				break
			now_length = 0
			for k in range(j+1, j+1+need_length):
				if board[i][k] + 1 == board[i][j] and bridge[i][k] == 0:
					now_length += 1
				else:
					now_length = 0
			if now_length >= need_length:
				for k in range(j+1, j+1+need_length):
					bridge[i][k] = 1
	if not fail:
		success_bridge += 1
print(success_bridge)
					



