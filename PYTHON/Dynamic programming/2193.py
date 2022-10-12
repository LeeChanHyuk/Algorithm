from sys import stdin

N = int(stdin.readline().strip())

D = [0] * 95

D[1] = 1
D[2] = 1
D[3] = 2
D[4] = 3

for i in range(1, 90):
    D[4+i] = D[3+i] + D[2+i]
print(D[N])