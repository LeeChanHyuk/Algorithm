from sys import stdin
from copy import deepcopy
from collections import deque

board = []
via = []
deque_ = deque()
dx = [1, 0, -1, 0]
dy = [0, -1, 0 ,1]

R, G, B, P, Y = [], [], [], [], []
bomb_dict = dict()
bomb_dict['R'] = [0, []] # [bomb_num, bomb_position_list]
bomb_dict['G'] = [0, []]
bomb_dict['B'] = [0, []]
bomb_dict['P'] = [0, []]
bomb_dict['Y'] = [0, []]
result = 0

for i in range(12):
    line = stdin.readline().strip()
    via.append([0] * 6)
    board.append(line)
        
def bomb_initialization(board, deque):
    R, G, B, P, Y = 0, 0, 0, 0, 0
    for i in range(12):
        for j in range(6):
            if line[j] == 'R' and R == 0:
                deque.append([[i, j], 'R'])
            elif line[j] == 'G' and G == 0:
                deque.append([[i, j], 'G'])
            elif line[j] == 'B' and B == 0:
                deque.append([[i, j], 'B'])
            elif line[j] == 'P' and P == 0:
                deque.append([[i, j], 'P'])
            elif line[j] == 'Y' and Y == 0:
                deque.append([[i, j], 'Y'])
    return deque
    

def bomb(bomb_dict, board):
    success = 0
    for color in ['R', 'G', 'B', 'P', 'Y']:
        if bomb_dict[color][0] < 4:
            continue
        for i in range(len(bomb_dict[color][1])):
            temp_y, temp_x = bomb_dict[color][1][i][0], bomb_dict[color][1][i][1]
            board[temp_y][temp_x] = 'K'
        success = 1
        
    # pull down of blank zone
    for i in range(12):
        for j in range(6):
            if board[i][j] == 'K':
                for k in range(0, j):
                    board[k][j] = board[k+1][j]
                board[0][j] = '.'
    
    # reset
    for color in ['R', 'G', 'B', 'P', 'Y']:
        bomb_dict[color] = [0, []]
    return board, bomb_dict, success
            
def bfs(board, via, deque, bomb_dict, result):
    via_save = deepcopy(via)
    while 1:
        deque = bomb_initialization(board, deque)
        via = deepcopy(via_save)
        while len(deque) > 0:
            [origin_y, origin_x], origin_color = deque.popleft()
            via[origin_y][origin_x] += 1
            for i in range(4):
                dest_y, dest_x = origin_y + dy[i], origin_x + dx[i]
                if dest_x < 0 or dest_y < 0 or dest_x >= 6 or dest_y >= 12:
                    continue
                if board[dest_y][dest_x] == '.' or board[dest_y][dest_x] != origin_color:
                    continue
                if via[dest_y][dest_x] > 0:
                    continue
                via[dest_y][dest_x] += 1
                deque.append([[dest_y, dest_x], origin_color])
                if bomb_dict[origin_color][0] == 0:
                    bomb_dict[origin_color][0] += 1
                    bomb_dict[origin_color][1].append([origin_y, origin_x])
                bomb_dict[origin_color][0] += 1
                bomb_dict[origin_color][1].append([dest_y, dest_x])
        board, bomb_dict, success = bomb(bomb_dict, board)
        if success == 0:
            break
        else:
            result += 1
    return result

result = bfs(board, via, deque_, bomb_dict, result)
print(result)
            






