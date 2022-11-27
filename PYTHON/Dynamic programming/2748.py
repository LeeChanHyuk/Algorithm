from sys import stdin

D = [0] * 100
D[0] = 0
D[1] = 1
D[2] = 1
for i in range(3, 100):
    D[i] = D[i-2] + D[i-1]

N = int(stdin.readline().strip())
print(D[N])