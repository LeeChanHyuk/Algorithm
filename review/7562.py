from cmath import inf
from sys import stdin

test_cases = int(stdin.readline().strip())
dx = [1, 2, 2, 1, -1, -2, -2, -1]
dy = [2, 1, -1, -2, -2 ,-1 ,1 ,2]
for test_case in range(test_cases):
	height = width = int(stdin.readline())
	origin_x, origin_y = map(int, stdin.readline().strip().split(' '))
	dest_x, dest_y = map(int, stdin.readline().strip().split(' '))

	via = [[inf for i in range(width)] for j in range(height)]
	via[origin_y][origin_x] = 0
	queue = []
	queue.append([origin_y, origin_x])
	while len(queue) > 0:
		temp_origin_y, temp_origin_x = queue.pop(0)
		if temp_origin_y == dest_y and temp_origin_x == dest_x:
			print(via[dest_y][dest_x])
			break
		temp_origin_via = via[temp_origin_y][temp_origin_x]
		for i in range(len(dx)):
			temp_dest_y, temp_dest_x = temp_origin_y + dy[i], temp_origin_x + dx[i]
			if temp_dest_y >= height or temp_dest_y < 0:
				continue
			if temp_dest_x >= width or temp_dest_x < 0:
				continue
			if via[temp_dest_y][temp_dest_x] > temp_origin_via + 1:
				via[temp_dest_y][temp_dest_x] = temp_origin_via + 1
				queue.append([temp_dest_y, temp_dest_x])