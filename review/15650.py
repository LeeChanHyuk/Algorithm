from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))

target_array = []

def back_tracking(N, M, k, prev_i):
	global target_array
	if k == M:
		for i in range(M):
			print(target_array[i], end=' ')
		print()
	else:
		for i in range(prev_i, N+1):
			target_array.append(i)
			back_tracking(N, M, k+1, i+1)
			target_array.pop()

back_tracking(N, M, 0, 1)
