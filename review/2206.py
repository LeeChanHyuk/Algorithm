from cmath import inf
from sys import stdin

height, width = map(int, stdin.readline().strip().split(' '))
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

board = []
queue = []
via = []

def initialize(width, height, board, via):
    for i in range(height):
        line = stdin.readline().strip()
        board.append(line)
    for j in range(2):
        temp_via = []
        for i in range(height):
            temp_via.append([inf] * width)
        via.append(temp_via.copy())

def bfs(board, queue, via, width, height):
    success = False
    queue.append((1, 0, 0))
    via[1][0][0] = 0
    via[0][0][0] = 0
    while len(queue) > 0:
        wall_break, origin_y, origin_x = queue.pop(0)
        for i in range(4):
            dest_x, dest_y = origin_x + dx[i], origin_y + dy[i]
            if dest_x >= width or dest_x < 0:
                continue
            if dest_y >= height or dest_y < 0:
                continue
            if dest_y + 1 == height and dest_x + 1 == width:
                success = True
                break
            if board[dest_y][dest_x] == '1':
                if via[wall_break][dest_y][dest_x] > via[wall_break][origin_y][origin_x] + 1 and wall_break:
                    queue.append((0, dest_y, dest_x))
                    via[0][dest_y][dest_x] = via[wall_break][origin_y][origin_x] + 1
                    via[1][dest_y][dest_x] = via[wall_break][origin_y][origin_x] + 1
                else:
                    continue
            elif via[wall_break][dest_y][dest_x] > via[wall_break][origin_y][origin_x] + 1:
                queue.append((wall_break, dest_y, dest_x))
                via[0][dest_y][dest_x] = via[wall_break][origin_y][origin_x] + 1
                via[1][dest_y][dest_x] = via[wall_break][origin_y][origin_x] + 1

    if success:
        print(via[wall_break][origin_y][origin_x] + 2)
    else:
        print(-1)

initialize(width=width, height=height, board=board, via=via)
bfs(board, queue, via, width, height)
