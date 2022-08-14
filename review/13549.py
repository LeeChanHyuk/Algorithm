from sys import stdin
from cmath import inf
from collections import deque


def bfs(subin, sister):
    queue = deque()
    queue.append(subin)
    while len(queue) > 0:
        origin_x = queue.popleft()
        for i in range(3):
            if i==0:
                dest_x = origin_x * 2
            elif i==1:
                dest_x = origin_x + 1
            elif i==2:
                dest_x = origin_x - 1
            if dest_x > 100000 or dest_x < 0:
                continue
            if via[dest_x] < via[origin_x] + 1:
                continue
            if dest_x == sister:
                if i > 0:
                    return via[origin_x] + 1
                else:
                    return via[origin_x]
            if i > 0:
                queue.append(dest_x)
            else:
                queue.appendleft(dest_x)
            if i > 0:
                via[dest_x] = via[origin_x] + 1
            else:
                via[dest_x] = via[origin_x]

subin, sister = map(int, stdin.readline().strip().split(' '))
via = [inf] * 100001
via[subin] = 0
time = bfs(subin, sister)
if time is None:
    print(0)
else:
    print(time)