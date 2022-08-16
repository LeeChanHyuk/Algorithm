from sys import stdin
from tracemalloc import start

N = int(stdin.readline())
board = []
for i in range(N):
    board.append([' '] * N)

def recursive(N, board, num, start_point):
    if N == 3:
        if num == 1:
            for i in range(3):
                for j in range(3):
                    if i==1 and j == 1:
                        board[start_point[0] + i][start_point[1] + j] = ' '
                    else:
                        board[start_point[0] + i][start_point[1] + j] = '*'
        else:
            for i in range(3):
                for j in range(3):
                    board[start_point[0] + i][start_point[1] + j] = ' '
    else:
        width = int(N/3)
        recursive(width, board, num, start_point)
        recursive(width, board, num, (start_point[0], start_point[1] + width))
        recursive(width, board, num, (start_point[0], start_point[1] + (2 *width)))
        recursive(width, board, num, (start_point[0] + width, start_point[1]))
        recursive(width, board, 0, (start_point[0] + width, start_point[1] + width))
        recursive(width, board, num, (start_point[0] + width, start_point[1] + (width * 2)))
        recursive(width, board, num, (start_point[0] + (width * 2), start_point[1]))
        recursive(width, board, num, (start_point[0] + (width * 2), start_point[1] + width))
        recursive(width, board, num, (start_point[0] + (width * 2), start_point[1] + (width * 2)))

recursive(N, board, 1, (0, 0))
for i in range(N):
    for j in range(N):
        print(board[i][j], end='')
    print()