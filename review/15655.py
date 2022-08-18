from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
candidate_array = list(map(int, stdin.readline().strip().split(' ')))
used_array = [0] * len(candidate_array)
candidate_array.sort()
target_array = []

def back_tracking(N, M, k, prev_i):
	global target_array
	if k == M:
		for i in range(M):
			print(target_array[i], end=' ')
		print()
	else:
		for i, num in enumerate(candidate_array):
			if i < prev_i:
				continue
			if used_array[i] != 1:
				target_array.append(num)
				used_array[i] = 1
				back_tracking(N, M, k+1, i+1)
				target_array.pop()
				used_array[i] = 0

back_tracking(N, M, 0, 0)


