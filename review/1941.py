import os
from sys import stdin

board = []
via = []
for i in range(5):
	input_list = stdin.readline().strip()
	for j in range(5):
		board.append(input_list[j])
		via.append(0)

horizontal_check = [0, 0, 0, 0, 0]
vertical_check = [0, 0, 0, 0, 0]
seven_princesses = []
seven_princesses_positions = []
result = 0
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

def bfs():
	global seven_princesses_positions, via
	# initialization for needy
	queue = []
	temp_via = via.copy()
	temp_seven_princess_position = seven_princesses_positions.copy()

	# bfs
	first_coord = temp_seven_princess_position.pop()
	queue.append(first_coord)
	temp_via[first_coord[0] * 5 + first_coord[1]] = 1
	student = 1
	while len(queue) > 0:
		origin_y, origin_x = queue.pop()
		for i in range(4):
			dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
			if dest_y >= 5 or dest_y < 0 or dest_x >= 5 or dest_x < 0:
				continue
			if temp_via[dest_y * 5 + dest_x] == 1:
				continue
			if (dest_y, dest_x) not in temp_seven_princess_position:
				continue
			temp_via[dest_y * 5 + dest_x] = 1
			queue.append((dest_y, dest_x))
			student += 1
	if student == 7:
		return True
	else:
		return False


def back_tracking(k, prev_i):
	global seven_princesses, result
	if k == 7:
		S = 0
		Y = 0
		for i in range(7):
			if seven_princesses[i] == 'Y':
				Y += 1
			else:
				S += 1
		if S >= 4:
			correct_seven_princess = bfs()
			if correct_seven_princess:
				result += 1
	else:
		for i in range(prev_i, 25):
			seven_princesses.append(board[i])
			seven_princesses_positions.append((int(i/5), i%5))
			back_tracking(k+1, i+1)
			seven_princesses.pop()
			seven_princesses_positions.pop()
back_tracking(0, 0)
print(result)






