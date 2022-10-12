from sys import stdin

N = int(stdin.readline().strip())
array = list(map(int, stdin.readline().strip().split(' ')))
D = [0] * N
D[0] = array[0]

max_num = D[0]
for i in range(1, N):
    temp = max(0, D[i-1])
    D[i] = temp + array[i]
    if D[i] > max_num:
        max_num = D[i]
print(max_num)
