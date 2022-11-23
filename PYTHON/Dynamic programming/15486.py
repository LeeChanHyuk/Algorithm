from sys import stdin

N = int(stdin.readline().strip())
arr = dict()
for i in range(N+1):
	arr[i] = []
for i in range(N):
	period, money = map(int, stdin.readline().strip().split(' '))
	if i+period < len(arr):
		arr[i+period].append([period, money])
D = [0] * (N+1)
max_val = 0
for i in range(N+1):
	if len(arr[i]) == 0:
		D[i] = max_val
	while len(arr[i]) > 0:
		period, money = arr[i].pop()
		D[i] = max(D[i], D[i-period] + money, max_val)
		if D[i] > max_val:
			max_val = D[i]
print(max(D))
