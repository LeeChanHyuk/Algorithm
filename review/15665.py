from sys import stdin
from unittest import result

N, M = map(int, stdin.readline().strip().split(' '))
candidate_array = list(map(int, stdin.readline().strip().split(' ')))
candidate_array.sort()
target_array = []
result_dict = dict()

def back_tracking(N, M, k):
	global target_array, result_dict
	if k == M:
		strs = ''
		for i in range(M):
			strs = strs + str(target_array[i]) + ' '
		if strs not in result_dict.keys():
			print(strs[0:-1])
			result_dict[strs] = 1
	else:
		for i, num in enumerate(candidate_array):
			target_array.append(num)
			back_tracking(N, M, k+1)
			target_array.pop()

back_tracking(N, M, 0)


