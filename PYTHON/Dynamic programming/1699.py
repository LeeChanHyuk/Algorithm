from sys import stdin

N = int(stdin.readline().strip())
D = [0] * (N+1)
for i in range(N+1):
    D[i] = i

for i in range(1, N+1):
    for j in range(1, i):
        if j ** 2 > i:
            break
        elif j ** 2 == i:
            D[i] = 1
        else:
            num = j**2
            D[i] = min(D[i], D[i-num] + 1)
print(D[N])