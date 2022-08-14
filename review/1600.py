from cmath import inf
from sys import stdin
from collections import deque

k = int(stdin.readline())
width, height = map(int, stdin.readline().split(' '))
board= []
via = []
dx = [1, 0, -1, 0, 1, 2, 2, 1, -1, -2, -2, -1]
dy = [0, -1, 0, 1, 2, 1, -1, -2, -2, -1, 1, 2]

# board initialize
for i in range(height):
    board.append(list(map(int, stdin.readline().strip().split(' '))))


# via intialize
for i in range(k+1):
    temp_via = []
    for j in range(height):
        temp_via.append([inf] * width)
    via.append(temp_via)

def bfs(height, width, board, via, k):
    queue = deque()
    queue.append([k, 0, 0])
    for i in range(k+1):
        via[i][0][0] = 0
    success = 0
    success_val = 0
    while len(queue) > 0 and success == 0:
        jump, origin_y, origin_x = queue.popleft()

        # jump case
        for i in range(4, 12):
            if jump <= 0:
                break
            dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
            if dest_y < 0 or dest_x < 0 or dest_x >= width or dest_y >= height:
                continue
            if dest_y == height-1 and dest_x == width-1:
                success = 1
                success_val = via[jump][origin_y][origin_x]
                break
            if board[dest_y][dest_x] == 1:
                continue
            if via[jump-1][dest_y][dest_x] <= via[jump][origin_y][origin_x] + 1:
                continue
            via[jump-1][dest_y][dest_x] = via[jump][origin_y][origin_x] + 1
            queue.append([jump-1, dest_y, dest_x])

        # Normal case
        for i in range(4):
            dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
            if dest_y < 0 or dest_x < 0 or dest_x >= width or dest_y >= height:
                continue
            if via[jump][dest_y][dest_x] <= via[jump][origin_y][origin_x] + 1:
                continue
            if board[dest_y][dest_x] == 1:
                continue
            if dest_y == height-1 and dest_x == width-1:
                success = 1
                success_val = via[jump][origin_y][origin_x]
                break
            via[jump][dest_y][dest_x] = via[jump][origin_y][origin_x] + 1
            queue.append([jump, dest_y, dest_x])
                
    if success == 0:
        print(-1)
    else:
        print(success_val + 1)

if height == 1 and width == 1:
    if board[0][0] == 0:
        print(0)
    else:
        print(-1)
else:
    bfs(height, width, board, via, k)