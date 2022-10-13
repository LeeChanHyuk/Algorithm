from sys import stdin

N = int(stdin.readline().strip())

day = []
money = []
for i in range(N):
    a, b = map(int, stdin.readline().strip().split(' '))
    day.append(a)
    money.append(b)

D = [0] * N
if day[0] == 1:
    D[0] = money[0]
for i in range(1, N):
    for j in range(i):
        D[i] = max(D[i], D[i-1])
        if j + day[j] - 1 == i:
            D[i] = max(D[i], D[j-1]+money[j])
    if day[i] == 1:
        D[i] = max(D[i], D[i-1]+money[i])
print(max(D))
