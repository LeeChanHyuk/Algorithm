from sys import stdin
from copy import deepcopy

N = int(stdin.readline().strip())
arr = list(map(int, stdin.readline().strip().split(' ')))
D = deepcopy(arr)
for i in range(0, N):
	for j in range(0, i):
		if arr[j] < arr[i]:
			D[i] = max(D[i], D[j] + arr[i])
print(max(D))