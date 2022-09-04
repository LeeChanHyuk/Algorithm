from sys import stdin
from copy import deepcopy

height, width, sticker_num = map(int, stdin.readline().strip().split())
result = 0

def rotate_sticker(sticker_height, sticker_width, sticker, direction):
	new_sticker = []
	if direction == 0:
		new_sticker = deepcopy(sticker)
	elif direction == 1:
		for i in range(len(sticker)):
			new_sticker.append([sticker[i][1], sticker_height -1 - sticker[i][0]])
	elif direction == 2:
		for i in range(len(sticker)):
			new_sticker.append([sticker_height-1-sticker[i][0], sticker_width - 1 - sticker[i][1]])
	elif direction == 3:
		for i in range(len(sticker)):
			new_sticker.append([sticker_width - 1 - sticker[i][1], sticker[i][0]])
	return new_sticker



# board initialization
board = []
for i in range(height):
	board.append([0] * width)

for each_sticker in range(sticker_num):
	sticker_height, sticker_width = map(int, stdin.readline().strip().split())

	# This process can be done by bfs, but I will do for using direct access to board
	sticker = []
	for i in range(sticker_height):
		temp_sticker = list(map(int, stdin.readline().strip().split()))
		for j in range(len(temp_sticker)):
			if temp_sticker[j] == 1:
				sticker.append([i, j])
	
	success = False
	for direction in range(4):
		if success:
			break
		temp_sticker = rotate_sticker(sticker_height, sticker_width, sticker, direction)
		for i in range(height):
			if success:
				break
			for j in range(width):
				if success:
					break
				temp_success = True
				for k in range(len(sticker)):
					if i + temp_sticker[k][0] >= height or j + temp_sticker[k][1] >= width:
						temp_success = False
						break
					if board[i+temp_sticker[k][0]][j+temp_sticker[k][1]] > 0:
						temp_success = False
						break
				if temp_success:
					for k in range(len(sticker)):
						board[i+temp_sticker[k][0]][j+temp_sticker[k][1]] = 1
						result += 1
					success = True
					break
print(result)
				


