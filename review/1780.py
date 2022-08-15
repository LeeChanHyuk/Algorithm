from sys import stdin


def recursive(N, start_position, num):
    global board
    if N == 3:
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
        num_1 = recursive(new_width, start_position, num)
        num_2 = recursive(new_width, (start_position[0], start_position[1] + new_width), num)
        num_3 = recursive(new_width, (start_position[0], start_position[1] + (2 * new_width)), num)
        num_4 = recursive(new_width, (start_position[0] + new_width, start_position[1]), num)
        num_5 = recursive(new_width, (start_position[0] + new_width, start_position[1] + new_width), num)
        num_6 = recursive(new_width, (start_position[0] + new_width, start_position[1] + (2 * new_width)), num)
        num_7 = recursive(new_width, (start_position[0] + (new_width * 2), start_position[1]), num)
        num_8 = recursive(new_width, (start_position[0] + (new_width * 2), start_position[1] + new_width), num)
        num_9 = recursive(new_width, (start_position[0] + (new_width * 2), start_position[1] + (2 * new_width)), num)
        if num_1==num_2==num_3==num_4==num_5==num_6==num_7==num_8==num_9==0:
            return 0
        elif num_1==num_2==num_3==num_4==num_5==num_6==num_7==num_8==num_9==1:
            return 1
        elif num_1==num_2==num_3==num_4==num_5==num_6==num_7==num_8==num_9==2:
            return 2
        else:
            return 3

N = int(stdin.readline())
board = []
for i in range(N):
    board.append(list(map(int, stdin.readline().strip().split(' '))))
num = [0, 0, 0]
num = recursive(N, (0, 0), num)
print(num[0])
print(num[1])
print(num[2])


