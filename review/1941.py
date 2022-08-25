import os
from sys import stdin
from turtle import back
from xml.dom import minicompat

board = []
via = []
for i in range(5):
	board.append(stdin.readline().strip())
	via.append([0] * 5)

horizontal_check = [0, 0, 0, 0, 0]
vertical_check = [0, 0, 0, 0, 0]
seven_princesses = []
result = 0
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
def back_tracking(k):
	global seven_princesses, result
	if k == 8:
		S = 0
		Y = 0
		for i in range(7):
			if seven_princesses[i] == 'Y':
				Y += 1
			else:
				S += 1
		if S >= 4:
			print(seven_princesses)
			result += 1
	else:
		for i in range(5):
			for j in range(5):
				if via[i][j] == 1:
					continue
				if k == 0:
					via[i][j] = 1
					seven_princesses.append(board[i][j])
					back_tracking(k+1)
					via[i][j] = 0
					seven_princesses.pop()
				success = 0
				for l in range(4):
					dest_i, dest_j = i + dy[l] , j + dx[l]
					if dest_i < 0 or dest_i > 4 or dest_j < 0 or dest_j > 4:
						continue
					if via[dest_i][dest_j] == 1:
						seven_princesses.append(board[i][j])
						via[i][j] = 1
						success = 1
						break
				if success:
					back_tracking(k+1)
					via[i][j] = 0
					seven_princesses.pop()
back_tracking(0)
print(result)






