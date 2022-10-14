from sys import stdin

test_case = int(stdin.readline().strip())
D = [1] * 100
for i in range(3, 100):
	D[i] = D[i-2] + D[i-3]
for i in range(test_case):
	N = int(stdin.readline().strip())
	print(D[N-1])