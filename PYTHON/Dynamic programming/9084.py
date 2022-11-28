from sys import stdin

test_case = int(stdin.readline().strip())
for case in range(test_case):
	N = int(stdin.readline().strip())
	coins = list(map(int, stdin.readline().strip().split(' ')))
	target = int(stdin.readline().strip())
	D = [0] * (target+1)
	for i in coins:
		D[i] = 1
	for i in range(1, target+1):
		for j in coins:
			if i-j > 0 and D[i-j] > 0:
				D[i] += (D[i-j] + 1)
	print(D[target])
