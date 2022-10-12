from sys import stdin

N = int(stdin.readline().strip())
arr = list(map(int, stdin.readline().strip().split(' ')))
D = [1] * N
# D[0] is maximum length of the arising array component.

for i in range(N):
    for j in range(i):
        if arr[i] > arr[j]:
            D[i] = max(D[i], D[j] + 1)
print(max(D))