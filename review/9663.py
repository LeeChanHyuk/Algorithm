from sys import stdin

N = int(stdin.readline().strip())

board = []
for i in range(N):
	board.append([0] * N)
method = 0

def horizontal_check(board, i, j, N):
	success = True
	for k in range(N):
		if board[i][k] == 1:
			success = False
			break
	return success

def vertical_check(board, i, j, N):
	success = True
	for k in range(N):
		if board[k][j] == 1:
			success = False
			break
	return success

def diagonal_check(board, i, j, N):
	success = True
	for k in range(N):
		if i-k >= 0 and j-k >= 0 and board[i-k][j-k] == 1:
			success = False
			break
		elif i+k < N  and j+k < N and board[i+k][j+k] == 1:
			success = False
			break
		elif i-k >= 0 and j+k < N and board[i-k][j+k] == 1:
			success = False
			break
		elif i+k < N and j-k >= 0 and board[i+k][j-k] == 1:
			success = False
			break
	return success

def back_tracking(k, N, prev_i):
	global method
	if k == N:
		method += 1
	else:
		for i in range(prev_i, N):
			for j in range(N):
				#if horizontal_check(board, i, j, N) is False:
				#	break
				if vertical_check(board, i, j, N) is False or diagonal_check(board, i, j, N) is False:
					continue
				board[i][j] = 1
				back_tracking(k+1, N, i+1)
				board[i][j] = 0

back_tracking(0, N, 0)
print(method)
