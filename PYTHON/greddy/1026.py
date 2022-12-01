from sys import stdin

N = int(stdin.readline().strip())
A = list(map(int, stdin.readline().strip().split(' ')))
B = list(map(int, stdin.readline().strip().split(' ')))

A.sort()
B.sort()
B.reverse()

result = 0
for i in range(len(A)):
	result += A[i] * B[i]
print(result)