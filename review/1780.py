from sys import stdin


def recursive(N, start_position, num):
    global board
    if N == 1:
        num[board[0][0]+1] += 1
    elif N == 3:
        temp = [0, 0, 0]
        for i in range(3):
            for j in range(3):
                if board[start_position[0] + i][start_position[1] + j] == -1:
                    temp[0] += 1
                elif board[start_position[0] + i][start_position[1] + j] == 0:
                    temp[1] += 1
                else:
                    temp[2] += 1
        if temp[0] == 9:
            return 0
        elif temp[1] == 9:
            return 1
        elif temp[2] == 9:
            return 2
        else:
            num[0] += temp[0]
            num[1] += temp[1]
            num[2] += temp[2]
            return 3
    else:
        new_width = int(N/3)
        temp_num = [0] * 9
        temp_num[0] = recursive(new_width, start_position, num)
        temp_num[1] = recursive(new_width, (start_position[0], start_position[1] + new_width), num)
        temp_num[2] = recursive(new_width, (start_position[0], start_position[1] + (2 * new_width)), num)
        temp_num[3] = recursive(new_width, (start_position[0] + new_width, start_position[1]), num)
        temp_num[4] = recursive(new_width, (start_position[0] + new_width, start_position[1] + new_width), num)
        temp_num[5] = recursive(new_width, (start_position[0] + new_width, start_position[1] + (2 * new_width)), num)
        temp_num[6] = recursive(new_width, (start_position[0] + (new_width * 2), start_position[1]), num)
        temp_num[7] = recursive(new_width, (start_position[0] + (new_width * 2), start_position[1] + new_width), num)
        temp_num[8] = recursive(new_width, (start_position[0] + (new_width * 2), start_position[1] + (2 * new_width)), num)
        if temp_num[0]==temp_num[1]==temp_num[2]==temp_num[3]==temp_num[4]==temp_num[5]==temp_num[6]==temp_num[7]==temp_num[8]==0:
            return 0
        elif temp_num[0]==temp_num[1]==temp_num[2]==temp_num[3]==temp_num[4]==temp_num[5]==temp_num[6]==temp_num[7]==temp_num[8]==1:
            return 1
        elif temp_num[0]==temp_num[1]==temp_num[2]==temp_num[3]==temp_num[4]==temp_num[5]==temp_num[6]==temp_num[7]==temp_num[8]==2:
            return 2
        else:
            for i in range(9):
                if temp_num[i] == 3:
                    continue
                num[temp_num[i]] += 1
            return 3
            

N = int(stdin.readline())
board = []
for i in range(N):
    board.append(list(map(int, stdin.readline().strip().split(' '))))
num = [0, 0, 0]
number = recursive(N, (0, 0), num)
if number < 3:
    num[number] += 1
print(num[0])
print(num[1])
print(num[2])


