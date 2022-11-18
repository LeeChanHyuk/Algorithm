from sys import stdin

def swap(arr, i, j):
	temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp
	return arr
	
def bubble_sort(arr):
	for i in range(len(arr)-1, 0, -1):
		for j in range(0, i):
			if arr[j] > arr[j+1]:
				arr = swap(arr, j, j+1)
	return arr

def quick_sort(arr, start_index, end_index):
	if end_index <= start_index + 1:
		return
	pivot = arr[start_index]
	left_index = start_index+1
	right_index = end_index-1
	while 1:
		while left_index <= right_index and arr[left_index] <= pivot:
			left_index += 1
		while left_index <= right_index and arr[right_index] >= pivot:
			right_index -= 1
		if left_index > right_index:
			break
		elif arr[left_index] > pivot and arr[right_index] < pivot:
			arr = swap(arr, left_index, right_index)
	arr = swap(arr, start_index, right_index)
	quick_sort(arr, start_index, right_index)
	quick_sort(arr, right_index+1, end_index)
	return arr

def merge(start_index, end_index):
	mid = int((start_index + end_index) // 2)
	left_index = start_index
	right_index = mid
	for i in range(start_index, end_index, 1):
		if right_index == end_index:
			temp[i] = nums[left_index]
			left_index += 1
		elif left_index == mid:
			temp[i] = nums[right_index]
			right_index += 1
		elif nums[left_index] <= nums[right_index]:
			temp[i] = nums[left_index]
			left_index += 1
		else:
			temp[i] = nums[right_index]
			right_index += 1
	for i in range(start_index, end_index, 1):
		nums[i] = temp[i]

def merge_sort(start_index, end_index):
	if end_index <= start_index + 1:
		return
	mid = int((start_index + end_index) // 2)
	merge_sort(start_index, mid)
	merge_sort(mid, end_index)
	merge(start_index, end_index)

N = int(stdin.readline().strip())
nums = []
temp = []
for i in range(N):
	nums.append(int(stdin.readline().strip()))
	temp.append(nums[-1])


merge_sort(0, len(nums))
for i in range(N):
	print(int(nums[i]))