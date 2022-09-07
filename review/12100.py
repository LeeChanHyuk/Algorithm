from sys import stdin
from copy import deepcopy
from unittest import TestProgram

N = int(stdin.readline().strip())
board = []
zero_board = []
for i in range(N):
	board.append(list(map(int, stdin.readline().strip().split(' '))))
	zero_board.append([0] * N)

result = 0

def slant(direction, board, zero_board):
	global N
	new_board = deepcopy(zero_board)
	if direction == 0:
		for i in range(N):
			pass_time = False
			pivot = N-1
			temp_num_list = []
			for j in range(N):
				if board[i][j] > 0:
					temp_num_list.append(board[i][j])
			for j in range(len(temp_num_list) - 1, -1, -1):
				if pass_time:
					pass_time = False
					continue
				elif j > 0:
					if temp_num_list[j] == temp_num_list[j-1]:
						new_board[i][pivot] = temp_num_list[j] + temp_num_list[j-1]
						pass_time = True
					else:
						new_board[i][pivot] = temp_num_list[j]
					pivot -= 1
				else:
					if temp_num_list[j] > 0:
						new_board[i][pivot] = temp_num_list[j]
	elif direction == 1:
		for j in range(N):
			pass_time = False
			pivot = N-1
			temp_num_list = []
			for i in range(N):
				if board[i][j] > 0:
					temp_num_list.append(board[i][j])
			for i in range(len(temp_num_list) - 1, -1, -1):
				if pass_time:
					pass_time = False
					continue
				elif i > 0:
					if temp_num_list[i] == temp_num_list[i-1]:
						new_board[pivot][j] = temp_num_list[i] + temp_num_list[i-1]
						pass_time = True
					else:
						new_board[pivot][j] = temp_num_list[i]
					pivot -= 1
				else:
					if temp_num_list[i] > 0:
						new_board[pivot][j] = temp_num_list[i]
	elif direction == 2:
		for i in range(N):
			pass_time = False
			pivot = 0
			temp_num_list = []
			for j in range(N):
				if board[i][j] >0:
					temp_num_list.append(board[i][j])
			for j in range(len(temp_num_list)):
				if pass_time:
					pass_time = False
					continue
				elif j < len(temp_num_list) - 1:
					if temp_num_list[j] == temp_num_list[j+1]:
						new_board[i][pivot] = temp_num_list[j] + temp_num_list[j+1]
						pass_time = True
					else:
						new_board[i][pivot] = temp_num_list[j]
					pivot += 1
				else:
					if temp_num_list[j] > 0:
						new_board[i][pivot] = temp_num_list[j]
	else:
		for j in range(N):
			pass_time = False
			pivot = 0
			temp_num_list = []
			for i in range(N):
				if board[i][j] > 0:
					temp_num_list.append(board[i][j])
			for i in range(len(temp_num_list)):
				if pass_time:
					pass_time = False
					continue
				elif i < len(temp_num_list) - 1:
					if temp_num_list[i] == temp_num_list[i+1]:
						new_board[pivot][j] = temp_num_list[i] + temp_num_list[i+1]
						pass_time = True
					else:
						new_board[pivot][j] = temp_num_list[i]
					pivot += 1
				else:
					if temp_num_list[i] > 0:
						new_board[pivot][j] = temp_num_list[i]
	return new_board
			
def back_tracking(k, board, zero_board):
	global N, result
	if k == 5:
		for i in range(N):
			for j in range(N):
				if board[i][j] > result:
					result = board[i][j]
	else:
		now_board = deepcopy(board)
		for direction in range(4):
			temp_board = slant(direction, now_board, zero_board)
			back_tracking(k+1, temp_board, zero_board)

back_tracking(0, board, zero_board)
print(result)
