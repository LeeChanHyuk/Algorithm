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
			target_array.append(num)
			back_tracking(N, M, k+1, i)
			target_array.pop()

back_tracking(N, M, 0, 0)


