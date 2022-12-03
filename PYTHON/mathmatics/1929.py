from sys import stdin

M, N = map(int, stdin.readline().strip().split(' '))
state = [1] * (N+1)
state[0] = 0
state[1] = 0

for i in range(2, N+1):
    if state[i] == 0:
        continue
    for j in range(i*i, N+1, i):
        state[j] = 0
result = []
for i in range(M, N+1):
    if state[i] == 1:
        print(i)
