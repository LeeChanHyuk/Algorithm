from sys import stdin
from copy import deepcopy

n, m = map(int, stdin.readline().strip().split(' '))
board = []
# get input
for i in range(n):
	line = stdin.readline().strip()
	board.append(list(map(int, line)))
D = deepcopy(board)
max_val = 0
for i in range(n):
	for j in range(m):
		if board[i][j] == 0:
			D[i][j] = 0
		elif i==0 or j==0:
			D[i][j] = board[i][j]
		else:
			D[i][j] = min(D[i-1][j], D[i][j-1], D[i-1][j-1]) + 1
		if D[i][j] > max_val:
			max_val = D[i][j]
print(max_val**2)