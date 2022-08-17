from sys import stdin

N = int(stdin.readline().strip())

board = []
for i in range(N):
	board.append([0] * N)
method = 0

vertical_check = [0] * N
right_diagonal_check = [0] * (2*N - 1)
left_diagonal_check = [0] * (2*N - 1)


def back_tracking(k, N):
	global method
	if k == N:
		method += 1
	else:
		for j in range(0, N):
			if vertical_check[j] == 1 or right_diagonal_check[j+k] == 1 or left_diagonal_check[j-k+N-1] == 1:
				continue
			vertical_check[j] = 1
			right_diagonal_check[j+k] = 1
			left_diagonal_check[j-k+N-1] = 1
			back_tracking(k+1, N)
			vertical_check[j] = 0
			right_diagonal_check[j+k] = 0
			left_diagonal_check[j-k+N-1] = 0
back_tracking(0, N)
print(method)
