from sys import stdin

class queue(object):
    def __init__(self):
        self.queue = []
        self.start_point = 0
        self.end_point = 0
    def enqueue(self, num):
        self.queue.append(num)
        self.end_point += 1
    def dequeue(self):
        self.start_point += 1
        return self.queue[self.start_point-1]
    def __len__(self):
        return self.end_point - self.start_point

subin, sister = map(int,stdin.readline().strip().split())
via = [0 for i in range(100001)]
position_queue = queue()
position_queue.enqueue(subin)
via[subin] = 1
while len(position_queue)>0:
    position = position_queue.dequeue()
    for i in range(3):
        if i == 0: # + 1
            moved_position = position + 1
            if moved_position < 0 or moved_position > 100000:
                continue
            if via[moved_position] < via[position] + 1 and via[moved_position] != 0:
                continue
            via[moved_position] = via[position] + 1
            position_queue.enqueue(moved_position)
        elif i == 1: # - 1
            moved_position = position - 1
            if moved_position < 0 or moved_position > 100000:
                continue
            if via[moved_position] < via[position] + 1 and via[moved_position] != 0:
                continue
            via[moved_position] = via[position] + 1
            position_queue.enqueue(moved_position)
        else:
            moved_position = position * 2
            if moved_position < 0 or moved_position > 100000:
                continue
            if via[moved_position] < via[position] + 1 and via[moved_position] != 0:
                continue
            via[moved_position] = via[position] + 1
            position_queue.enqueue(moved_position)
    if via[sister] > 0:
        print(via[sister] - 1)
        break



