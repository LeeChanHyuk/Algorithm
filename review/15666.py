from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
candidate_array = list(set(map(int, stdin.readline().strip().split(' '))))
candidate_array.sort()
target_array = []
result_list = []

def back_tracking(N, M, k):
	global target_array, result_list
	if k == M:
		print(*target_array)
	else:
		for i, num in enumerate(candidate_array):
			if k == 0:
				target_array.append(num)
				back_tracking(N, M, k+1)
				target_array.pop()
			elif num >= target_array[k-1]:
				target_array.append(num)
				back_tracking(N, M, k+1)
				target_array.pop()

back_tracking(N, M, 0)

