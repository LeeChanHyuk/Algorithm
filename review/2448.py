from sys import stdin
import sys

N = int(stdin.readline())
print = sys.stdout.write
width = 5 * int(N/3) + int(N/3)
board = []
for i in range(N):
    line = [' '] * width
    line[0] = ''
    board.append(line)

def recursive(height, start_point):
    global board
    if height == 3:
        board[start_point[0]][start_point[1]] = '*'
        board[start_point[0]+1][start_point[1]-1] = '*'
        board[start_point[0]+1][start_point[1]+1] = '*'
        board[start_point[0]+2][start_point[1]-2] = '*'
        board[start_point[0]+2][start_point[1]-1] = '*'
        board[start_point[0]+2][start_point[1]+0] = '*'
        board[start_point[0]+2][start_point[1]+1] = '*'
        board[start_point[0]+2][start_point[1]+2] = '*'
    else:
        height = int(height/2)
        recursive(height, start_point)
        recursive(height, (start_point[0] + height, start_point[1] - height))
        recursive(height, (start_point[0] + height, start_point[1] + height))
recursive(N, (0, int(width/2)))
for i in range(N):
    for j in range(width):
        print("%s" % board[i][j])
    if i<N-1:
        print('\n')

