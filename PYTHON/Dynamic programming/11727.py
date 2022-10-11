from sys import stdin

N = int(stdin.readline().strip())
D = [0] * 1010

D[0] = 0
D[1] = 1
D[2] = 3

for i in range(3, N+1):
    D[i] = (D[i-1] + 2 * D[i-2]) % 10007
print(D[N]) 