from sys import stdin

class queue(object):
    def __init__(self):
        self.queue = []
        self.queue_front = 0
        self.queue_end = 0

    def enqueue(self, num):
        self.queue.append(num)
        self.queue_end += 1

    def dequeue(self):
        self.queue_front += 1
        return self.queue[self.queue_front - 1]

    def __len__(self):
        return self.queue_end - self.queue_front

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

test_case = int(stdin.readline().strip())
for test in range(test_case):
    width, height, position_num = map(int,stdin.readline().strip().split())
    cabbage_position_queue = queue()
    board = []
    via = []
    for i in range(height):
        board.append([0 for j in range(width)])
        via.append([0 for j in range(width)])
    for position in range(position_num):
        x, y = map(int,stdin.readline().strip().split())
        board[y][x] = 1
    warm_num = 0
    for i in range(height):
        for j in range(width):
            if board[i][j] == 1 and via[i][j] == 0:
                cabbage_position_queue.enqueue((i, j))
                while len(cabbage_position_queue)>0:
                    (y, x) = cabbage_position_queue.dequeue()
                    via[y][x] = 1
                    for j in range(4):
                        y_pos, x_pos = y + dy[j], x + dx[j]
                        if y_pos > height - 1 or x_pos > width - 1 or y_pos < 0 or x_pos < 0:
                            continue
                        if via[y_pos][x_pos] == 1 or board[y_pos][x_pos] == 0:
                            continue
                        via[y_pos][x_pos] = 1
                        cabbage_position_queue.enqueue((y_pos, x_pos))
                warm_num += 1
    print(warm_num)







