from sys import stdin

N = int(stdin.readline().strip())

D = [[0] * 10 for i in range(N+1)]
for i in range(1, 10):
	D[1][i] = 1

for i in range(2, N+1):
	for j in range(0, 10):
		if j == 0:
			D[i][j] = D[i-1][1]
		elif j == 9:
			D[i][j] = D[i-1][8]
		else:
			D[i][j] = D[i-1][j-1] + D[i-1][j+1]
print(sum(D[N]) % 1000000000)
