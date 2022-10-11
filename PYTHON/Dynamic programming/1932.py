from re import A
from sys import stdin

D = [[0] * 500 for i in range(500)]
N = int(stdin.readline().strip())
data = [[0] * N for i in range(N)]
for i in range(N):
    if i == 0:
        data[0][0] = int(stdin.readline().strip())
    else:
        input_list = list(map(int, stdin.readline().strip().split(' ')))
        for j in range(i+1):
            data[i][j] = input_list[j]

def memorization(data, D, N):
    for i in range(1, N):
        for j in range(0, i+1):
            D[i][j] = max(D[i-1][max(0, j-1)], D[i-1][j]) + data[i][j]
    max_val = 0
    for i in range(N):
        if max_val < D[N-1][i]:
            max_val = D[N-1][i]
    print(max_val)
D[0][0] = data[0][0]
memorization(data, D, N)
