from sys import stdin
board = [0] * 100001
via = [100003] * 100001
subin, sister = map(int, stdin.readline().strip().split(' '))
board[subin] = 1
board[sister] = 2
via[subin] = 1
min_time = 0
queue = []
queue.append(subin)
while len(queue) > 0:
    pos = queue.pop(0)
    now_via = via[pos] + 1
    if pos+1 < 100001 and now_via < via[pos+1]:
        if pos+1 == sister:
            via[sister] = now_via
        else:
            queue.append(pos+1)
            via[pos+1] = now_via
    if pos-1 >= 0 and now_via < via[pos-1]:
        queue.append(pos-1)
        via[pos-1] = now_via
    if pos*2 < 100001 and now_via < via[pos*2]:
        if pos*2 == sister:
            via[sister] = now_via
        else:
            queue.append(pos*2)
            via[pos*2] = now_via
print(via[sister] - 1)
    