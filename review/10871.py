from sys import stdin
N, X = map(int, stdin.readline().strip().split(' '))
numbers = list(map(int, stdin.readline().strip().split(' ')))
for i in range(len(numbers)):
	if numbers[i] < X:
		print(numbers[i], sep=' ')
	