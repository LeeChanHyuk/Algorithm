from cmath import inf
from sys import stdin
from collections import deque

height, width = map(int, stdin.readline().strip().split(' '))
ice = []
via = []
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
for i in range(height):
    ice.append(list(map(int, stdin.readline().strip().split(' '))))
    via.append([inf] * width)

queue = deque()
rest_ice = deque()
for i in range(height):
    for j in range(width):
        if ice[i][j] > 0:
            rest_ice.append([i, j])

year = -1
success = 0
while len(rest_ice) > 0:
    previous_rest_ice_num = len(rest_ice)
    if previous_rest_ice_num == 0:
        print(0)
        break
    queue.append(rest_ice[0])
    year += 1
    via[rest_ice[0][0]][rest_ice[0][1]] = year
    rest_ice = [rest_ice[0]]

    current_ice_num = 0
    gone_ice = []
    while len(queue) > 0:
        origin_y, origin_x = queue.popleft()
        current_ice_num += 1
        for i in range(4):
            dest_x, dest_y = origin_x + dx[i], origin_y + dy[i]
            if dest_x < 0 or dest_x >= width or dest_y < 0 or dest_y >= height:
                continue
            if ice[dest_y][dest_x] <= 0:
                if ice[origin_y][origin_x] - 1 <= 0 and [origin_y, origin_x] in rest_ice:
                    index = rest_ice.index([origin_y, origin_x])
                    gone_ice.append([origin_y, origin_x])
                    del rest_ice[index]
                elif [origin_y, origin_x] not in gone_ice:
                    ice[origin_y][origin_x] -= 1
            elif via[dest_y][dest_x] == year:
                continue
            else: # ice[dest_y][dest_x] >= 1
                queue.append([dest_y, dest_x])
                rest_ice.append([dest_y, dest_x])
                via[dest_y][dest_x] = year
    for (i, j) in gone_ice:
        ice[i][j] = 0
    if previous_rest_ice_num != current_ice_num:
        success = 1
        print(year)
        break
if success == 0:
    print(0)