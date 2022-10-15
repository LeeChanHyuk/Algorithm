from sys import stdin

board = []
target = [0, 0]
for i in range(10):
    line = list(map(int, stdin.readline().strip().split(' ')))
    board.append(line)
    for j in range(10):
        if line[j] == 2:
            target = [i, j]



dx = [1, 0]
dy = [0, 1]

origin_y, origin_x = 1, 1
board[origin_y][origin_x] = 9
while 1:
    dest_y, dest_x = origin_y + dy[0], origin_x + dx[0]
    if (dest_x > 0 and dest_x < 9) and \
        (dest_y > 0 and dest_y < 9):
        if board[dest_y][dest_x] == 0:
            board[dest_y][dest_x] = 9
            origin_y, origin_x = dest_y, dest_x
            continue
        elif board[dest_y][dest_x] == 2:
            board[dest_y][dest_x] = 9
            break
    dest_y, dest_x = origin_y + dy[1], origin_x + dx[1]
    if (dest_x > 0 and dest_x < 9) and \
        (dest_y > 0 and dest_y < 9):
        if board[dest_y][dest_x] == 0:
            board[dest_y][dest_x] = 9
            origin_y, origin_x = dest_y, dest_x
            continue
        elif board[dest_y][dest_x] == 2:
            board[dest_y][dest_x] = 9
            break
    break

for i in range(10):
    for j in range(10):
        print(board[i][j], end=' ')
    print()

        
