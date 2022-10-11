from sys import stdin
from collections import deque

via = [0] * 1000010

def bfs(N):
    queue = deque()
    success = False
    queue.append(1)
    while len(queue)>0:
        origin_x = queue.popleft()
        for i in range(3):
            if i == 0:
                dest_x = origin_x * 3
            elif i == 1:
                dest_x = origin_x * 2
            else:
                dest_x = origin_x + 1
            if dest_x > N or dest_x <= 0:
                continue
            if via[dest_x] != 0 and via[origin_x] + 1 >= via[dest_x]:
                continue
            if dest_x == N:
                print(via[origin_x] + 1)
                success = True
                break
            queue.append(dest_x)
            via[dest_x] = via[origin_x] + 1
        if success:
            break

N = int(stdin.readline().strip())
if N == 1:
    print(0)
else:
    bfs(N=N)

