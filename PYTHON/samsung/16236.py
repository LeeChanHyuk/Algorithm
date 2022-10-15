from sys import stdin
from collections import deque
from copy import deepcopy

N = int(stdin.readline().strip())
fish = []
shark = []
board = []
via = []
for i in range(N):
    line = list(map(int, stdin.readline().strip().split(' ')))
    board.append(line)
    via.append([0] * N)
    for j in range(N):
        if line[j] > 0 and line[j] < 7:
            fish.append([[i, j], line[j]]) # [position, size]
        elif line[j] == 9:
            shark.append([[i, j], 2, 0, 0]) # [position, size, time]
dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

def rest_fish_check():
    global shark, fish
    # fish check
    for i in range(len(fish)):
        if shark[0][1] > fish[i][1]:
            return True
    return False

def after_eat(dest_y, dest_x):
    global shark, fish, via

    # shark size, position reinit
    shark[0][2] += 1
    if shark[0][2] == shark[0][1]:
        shark[0][1] += 1 # size
        shark[0][2] = 0 # eat fish number
    shark[0][0] = [dest_y, dest_x] # position
    shark[0][3] += 1 # time up

    rest_fish = rest_fish_check()
    return rest_fish, via



def bfs():
    global board, via, shark, fish
    temp_via = deepcopy(via)
    queue = deque()
    queue.append(shark[0][0])
    rest_fish = rest_fish_check()
    if rest_fish is False:
        return
    while len(queue) > 0:
        origin_y, origin_x = queue.popleft()
        temp_via[origin_y][origin_x] = 1
        for i in range(4):
            dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
            if dest_x >= N or dest_x < 0 or dest_y >= N or dest_y < 0:
                continue
            elif temp_via[dest_y][dest_x] == 1:
                continue
            elif board[dest_y][dest_x] > shark[0][1]:
                continue
            elif board[dest_y][dest_x] > 0 and shark[0][1] > board[dest_y][dest_x]:
                rest_fish, temp_via = after_eat(dest_y=dest_y, dest_x=dest_x)
                queue = deque()
                queue.append([dest_y, dest_x])
                if rest_fish is False:
                    return
                break
            else:
                shark[0][3] += 1
                queue.append([dest_y, dest_x])
                temp_via[dest_y][dest_x] = 1
bfs()
print(shark[0][3])
                

                



