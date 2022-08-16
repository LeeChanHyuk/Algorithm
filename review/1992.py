from sys import stdin

N = int(stdin.readline())
board = []
for i in range(N):
    line = stdin.readline().strip()
    board.append([int(line[i]) for i in range(N)])

def recursive(N, board, start_point):
    if N == 2:
        nums = [0, 0, 0, 0]
        nums[0] = board[start_point[0]][start_point[1]]
        nums[1] = board[start_point[0]][start_point[1] + 1]
        nums[2] = board[start_point[0] + 1][start_point[1]]
        nums[3] = board[start_point[0] + 1][start_point[1] + 1]
        if nums[0] == nums[1] == nums[2] == nums[3] == 0:
            return '0'
        elif nums[0] == nums[1] == nums[2] == nums[3] == 1:
            return '1'
        else:
            strs = '('
            for i in range(4):
                strs += str(nums[i])
            strs += ')'
            return strs

    else:
        nums = ['0', '0', '0', '0']
        width = int(N/2)
        return_num = 0
        nums[0] = recursive(width, board, (start_point[0], start_point[1]))
        nums[1] = recursive(width, board, (start_point[0], start_point[1] + width))
        nums[2] = recursive(width, board, (start_point[0] + width, start_point[1]))
        nums[3] = recursive(width, board, (start_point[0] + width, start_point[1] + width))
        if nums[0] == nums[1] == nums[2] == nums[3] == '0':
            return '0'
        elif nums[0] == nums[1] == nums[2] == nums[3] == '1':
            return '1'
        else:
            strs = '('
            for i in range(4):
                strs += nums[i]
            strs += ')'
        return strs

if N == 1:
    print('(' + board[0][0] + ')')
number = recursive(N, board, (0, 0))
print(number)



