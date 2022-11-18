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


N = int(stdin.readline().strip())
nums = []
for i in range(N):
	nums.append(int(stdin.readline().strip()))

nums = bubble_sort(nums)
for i in range(N):
	print(nums[i])
