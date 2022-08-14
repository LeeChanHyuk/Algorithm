from sys import stdin
from collections import deque

dx = [1, 0, -1 ,0]
dy = [0, -1, 0, 1]

# return the board and positions of lands
def get_board(height, width): # 공간복잡도 = O(N)
    board = []
    via = []
    lands_positions = set()
    for i in range(height):
        board.append(list(map(int, stdin.readline().strip().split(' '))))
        via.append([10002] * width)
        temp_positions = set()
        for j in range(width):
            if board[i][j] == 1:
                temp_positions.add((i, j))
        lands_positions = lands_positions.union(temp_positions)
    return board, via, lands_positions

def bfs(height, width, board, via, lands_positions):
    land_number = 0
    lands = dict()
    while len(lands_positions) > 0:
        queue = deque()
        start_y, start_y = 0, 0
        for i in lands_positions:
            start_y, start_x = i
            break
        queue.append([start_y, start_x])
        via[start_y][start_x] = 0
        land_number += 1
        board[start_y][start_x] = land_number
        lands_positions.remove((start_y, start_x))
        lands[land_number] = [queue[0]]
        while len(queue) > 0:
            origin_y, origin_x = queue.popleft()
            for i in range(4):
                dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]

                # RANGE EXCEPTION
                if dest_y < 0 or dest_x < 0 or dest_y >= height or dest_x >= width:
                    continue

                # BOARD EXCEPTION # don't care about the two land is connected.
                if board[dest_y][dest_x] == 0:
                    if not [origin_y, origin_x] in lands[land_number]:
                        lands[land_number].append([origin_y, origin_x])
                    continue

                # VIA EXCEPTION
                if via[dest_y][dest_x] != 10002 and via[dest_y][dest_x] <= via[origin_y][origin_x] + 1:
                    continue
                via[dest_y][dest_x] = via[origin_y][origin_x] + 1
                board[dest_y][dest_x] = land_number
                lands_positions.remove((dest_y, dest_x))
                queue.append([dest_y, dest_x])

    return land_number, lands

def cal_distance2(height, width, board, via, lands, land_number):
    min = 100000
    for land in range(land_number - 1):
        land += 1
        queue = deque()
        for k in range(len(lands[land])):
            queue.append(lands[land][k])
            via[queue[0][0]][queue[0][1]] = 0
            while len(queue) > 0:
                origin_y, origin_x = queue.popleft()
                for j in range(4):
                    dest_y, dest_x = origin_y + dy[j], origin_x + dx[j]

                    # RANGE EXCEPTION
                    if dest_y < 0 or dest_x < 0 or dest_y >= height or dest_x >= width:
                        continue

                    if board[dest_y][dest_x] != land and board[dest_y][dest_x] >= 1:
                        if via[origin_y][origin_x] + 1 < min:
                            min = via[origin_y][origin_x] + 1

                    # BOARD EXCEPTION # don't care about the two land is connected.
                    if board[dest_y][dest_x] != 0:
                        continue

                    # VIA EXCEPTION
                    if via[dest_y][dest_x] != 10002 and via[dest_y][dest_x] <= via[origin_y][origin_x] + 1:
                        continue

                    via[dest_y][dest_x] = via[origin_y][origin_x] + 1
                    queue.append([dest_y, dest_x])
    print(min - 1)




def cal_distance(land_number, lands):
    min = 200 # always the distance is larger than 200
    for i in range(1, land_number + 1):
        for j in range(1, land_number + 1):
            if i>=j:
                continue
            for k in range(len(lands[i])):
                point_1 = lands[i][k]
                for l in range(len(lands[j])):
                    point_2 = lands[j][l]
                    distance = abs(point_2[1] - point_1[1]) + abs(point_2[0] - point_1[0])
                    if distance < min:
                        min = distance
    print(min-1)

width = height = int(stdin.readline())
board, via, lands_positions = get_board(height = height, width = width)
land_number, lands = bfs(height, width, board, via, lands_positions)
#cal_distance(land_number, lands)
cal_distance2(height, width, board, via, lands, land_number)