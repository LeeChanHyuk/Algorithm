from sys import stdin

N = int(stdin.readline().strip())

nums = []
temps = []

def swap(a, b):
	global nums, temps
	temps[a] = nums[b]
	temps[b] = nums[a]

for i in range(N):
	num = int(stdin.readline().strip())
	nums.append(num)
	temps.append(num)

def quick_sort(start_index, end_index):
	global nums, temps
	if end_index - start_index <= 2:
		return
	pivot = nums[start_index]
	left_index = start_index + 1
	right_index = end_index - 1
	while 1:
		while left_index <= right_index and nums[left_index] <= pivot:
			left_index += 1
		while left_index <= right_index and nums[right_index] >= pivot:
			right_index -= 1
		if left_index > right_index:
			break
		swap(left_index, right_index)
	swap(start_index, right_index)
	for i in range(start_index, end_index):
		nums[i] = temps[i]
	quick_sort(start_index, right_index)
	quick_sort(right_index+1, end_index)

def merge(start_index, end_index):
	global nums, temps
	mid = int((start_index + end_index) // 2)
	left_index = start_index
	right_index = mid
	for i in range(start_index, end_index, 1):
		if left_index == mid:
			temps[i] = nums[right_index]
			right_index += 1
		elif right_index == end_index:
			temps[i] = nums[left_index]
			left_index += 1
		elif nums[left_index] >= nums[right_index]:
			temps[i] = nums[left_index]
			left_index += 1
		else:
			temps[i] = nums[right_index]
			right_index += 1
	for i in range(start_index, end_index, 1):
		nums[i] = temps[i]


def merge_sort(start_index, end_index):
	if end_index - start_index <= 1:
		return
	mid = int((start_index + end_index) // 2)
	merge_sort(start_index, mid)
	merge_sort(mid, end_index)
	merge(start_index, end_index)


merge_sort(0, len(nums))
for i in range(len(nums)):
	print(nums[i])
		
	

	