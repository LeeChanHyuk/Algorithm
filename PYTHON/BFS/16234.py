from sys import stdin
from collections import deque
from copy import deepcopy

N, L, R = map(int, stdin.readline().strip().split(' '))
board = []
via = []
input_array = deque()
for i in range(N):
	board.append(list(map(int, stdin.readline().strip().split(' '))))
	via.append([0] * N)
	for j in range(N):
		input_array.append([i, j])

def main(board, via, N, input_array):
	movement = 0
	while 1:
		queue = deque()
		temp_input_array = deepcopy(input_array)
		temp_via = deepcopy(via)
		temp_via, country_average, success = bfs(board, temp_via, queue, N, temp_input_array)
		if success:
			board = update(N, board, temp_via, country_average)
			movement += 1
		else:
			print(movement)
			break

def bfs(board, via, queue, N, input_array):
	dx = [1, 0 ,-1, 0]
	dy = [0, -1, 0, 1]
	via_count = 0
	country_average = []
	country_sum = 0
	country_count = 0
	success = False
	while len(input_array) > 0:
		input_y, input_x = input_array.popleft()
		if via[input_y][input_x] > 0:
			continue
		country_sum = board[input_y][input_x]
		country_count = 1
		queue.append([input_y, input_x])
		via_count += 1
		while len(queue) > 0:
			origin_y, origin_x = queue.popleft()
			via[origin_y][origin_x] = via_count
			for i in range(4):
				dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
				if dest_y >= N or dest_y < 0 or dest_x >= N or dest_x < 0:
					continue
				elif via[dest_y][dest_x] != 0:
					continue
				elif abs(board[origin_y][origin_x] - board[dest_y][dest_x]) < L or \
					abs(board[origin_y][origin_x] - board[dest_y][dest_x]) > R:
					continue
				via[dest_y][dest_x] = via_count
				queue.append([dest_y, dest_x])
				country_sum += board[dest_y][dest_x]
				country_count += 1
				success = True
		country_average.append([country_sum, country_count])
	return via, country_average, success
	
def update(N, board, via, country_average):
	average = []
	for i in range(len(country_average)):
		via_count = i+1
		country_sum = country_average[i][0]
		country_count = country_average[i][1]
		average.append(country_sum // country_count)

	for i in range(N):
		for j in range(N):
			board[i][j] = average[via[i][j]-1]
	
	return board

main(board, via, N, input_array)

