from sys import stdin
from copy import deepcopy

row, col = map(int, stdin.readline().strip().split())
board = []
cctvs = []
for i in range(row):
	inputs = list(map(int, stdin.readline().strip().split(' ')))
	for j in range(col):
		if inputs[j] > 0 and inputs[j] < 6:
			cctvs.append([inputs[j], (i, j)]) # cctv_sort, position
	board.append(inputs)

result = 100

def cctv_route_calculation(cctv):
	if cctv == 1:
		return [[(0, 1)], [(-1, 0)], [(0, -1)], [(1, 0)]] #[(route1), (route2), ...]
	elif cctv == 2:
		return [[(0, -1), (0, 1)], [(1, 0), (-1, 0)]]
	elif cctv == 3:
		return [[(1, 0), (0, 1)], [(0, 1), (-1, 0)], [(-1, 0), (0, -1)], [(0, -1), (1, 0)]]
	elif cctv == 4:
		return [[(0, -1), (1, 0), (0, 1)], [(1, 0), (0, 1), (-1, 0)], [(0, 1), (-1, 0), (0, -1)], [(-1, 0), (0, -1), (1, 0)]]
	elif cctv == 5:
		return [[(1, 0), (0, 1), (-1, 0), (0, -1)]]


def back_tracking(k, temp_board):
	global cctvs, row, col, result
	zero_num = 0
	if k == len(cctvs):
		for i in range(row):
			for j in range(col):
				if temp_board[i][j] == 0:
					zero_num += 1
		if zero_num < result:
			result = zero_num
	else:
		cctv = cctvs[k]
		cctv_directions = cctv_route_calculation(cctv[0])
		cctv_position = cctv[1]
		save_board = deepcopy(temp_board)
		for i in range(len(cctv_directions)):
			cctv_direction = cctv_directions[i]
			for j in range(len(cctv_direction)):
				(dy, dx) = cctv_direction[j]
				(origin_y, origin_x) = cctv_position
				dest_y, dest_x = origin_y, origin_x
				while 1:
					dest_y, dest_x = dest_y + dy, dest_x + dx
					if dest_x < 0 or dest_x >= col or dest_y < 0 or dest_y >= row:
						break
					if temp_board[dest_y][dest_x] == 6:
						break
					temp_board[dest_y][dest_x] = 7
			back_tracking(k+1, temp_board)
			temp_board = deepcopy(save_board)

back_tracking(0, deepcopy(board))
print(result)



