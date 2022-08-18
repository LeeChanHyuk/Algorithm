from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
candidate_array = list(map(int, stdin.readline().strip().split(' ')))
used_array = [0] * len(candidate_array)
candidate_array.sort()
target_array = []
dict = dict()

def back_tracking(N, M, k):
	global target_array, dict
	if k == M:
		strs = ''
		for i in range(M):
			strs = strs + str(target_array[i]) + ' '
		if strs not in dict.keys():
			print(strs[0:-1])
			dict[strs] = 1
	else:
		for i, num in enumerate(candidate_array):
			if used_array[i] == 1:
				continue
			used_array[i] = 1
			target_array.append(num)
			back_tracking(N, M, k+1)
			used_array[i] = 0
			target_array.pop()

back_tracking(N, M, 0)


