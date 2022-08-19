from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
candidate_array = list(map(int, stdin.readline().strip().split(' ')))
used_array = [0] * len(candidate_array)
index_array = []
candidate_array.sort()
target_array = []
total_list = []

def back_tracking(N, M, k):
	global target_array, total_list
	if k == M:
		temp_set = set()
		temp_set2 = set()
		strs = ''
		for i in range(M):
			temp_set.add(index_array[i])
			temp_set2.add(target_array[i])
			strs = strs + str(target_array[i]) + ' '
		if temp_set not in total_list and temp_set2 not in total_list:
			print(strs[0:-1])
			total_list.append(temp_set)
			total_list.append(temp_set2)
	else:
		for i, num in enumerate(candidate_array):
			if used_array[i] == 1:
				continue
			index_array.append(i)
			used_array[i] = 1
			target_array.append(num)
			back_tracking(N, M, k+1)
			used_array[i] = 0
			target_array.pop()
			index_array.pop()

back_tracking(N, M, 0)


