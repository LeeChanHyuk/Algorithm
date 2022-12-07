from sys import stdin

N = int(stdin.readline().strip())
arr = list(map(int, stdin.readline().strip().split(' ')))
M = int(stdin.readline().strip())
target_arr = list(map(int, stdin.readline().strip().split(' ')))
temp = [0] * len(arr)

def merge(start_index, end_index):
	if end_index - start_index < 2:
		return
	mid = int((start_index + end_index)/2)
	left_index = start_index
	right_index = mid
	idx = start_index
	while idx < end_index:
		if right_index == end_index:
			temp[idx] = arr[left_index]
			left_index += 1
		elif left_index == mid:
			temp[idx] = arr[right_index]
			right_index += 1
		elif arr[left_index] < arr[right_index]:
			temp[idx] = arr[left_index]
			left_index += 1
		else:
			temp[idx] = arr[right_index]
			right_index += 1
		idx += 1
	for i in range(start_index, end_index):
		arr[i] = temp[i]
	
def merge_sort(start_index, end_index):
	if end_index - start_index < 2:
		return
	mid = int((start_index + end_index)/2)
	merge_sort(start_index, mid)
	merge_sort(mid, end_index)
	merge(start_index, end_index)

merge_sort(0, len(arr))
success = False
def find_num(num, start_index, end_index):
	global success
	if end_index - start_index == 1:
		if num == arr[start_index] and success == False:
			success = True
			print(1)
	else:
		mid = int((start_index + end_index)/2)
		if num >= arr[mid]:
			find_num(num, mid, end_index)
		elif num >= arr[start_index]:
			find_num(num, start_index, mid)
	
for i in target_arr:
	find_num(i, 0, len(arr))
	if success == False:
		print(0)
	success = False
	
