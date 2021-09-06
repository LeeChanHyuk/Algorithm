from sys import stdin
command_num = int(stdin.readline().strip())
queue = [i for i in range(1, command_num+1)]
front = 0
while len(queue) != front + 1:
    front += 1
    queue.append(queue[front])
    front += 1
print(queue[front])