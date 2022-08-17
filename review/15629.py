from sys import stdin

N, M = map(int, stdin.readline().split(' '))

array_list = [0] * (M + 1)
used_num_list = [0] * (N + 1) # 1 ~ M

def back_tracking(k, N, M, array_list, used_num_list):
	if k == M+1:
		for i in range(1, M+1):
			print(array_list[i], end=' ')
		print()
		return
	else:
		for i in range(1, N+1):
			if used_num_list[i] != 1:
				array_list[k] = i
				used_num_list[i] = 1
				back_tracking(k+1, N, M, array_list, used_num_list)
				used_num_list[i] = 0

back_tracking(1, N, M, array_list, used_num_list)
