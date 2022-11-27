from sys import stdin

line1 = stdin.readline().strip()
line2 = stdin.readline().strip()

board = [[0] * (len(line2)+1) for i in range(len(line1)+1)]

max_num = 0
for i in range(1, len(line1)+1):
    for j in range(1, len(line2)+1):
        if line1[i-1] == line2[j-1]:
            board[i][j] = board[i-1][j-1] + 1
        else:
            board[i][j] = max(board[i-1][j], board[i][j-1])
        if board[i][j] > max_num:
            max_num = board[i][j]
print(max_num)