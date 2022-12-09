from sys import stdin

N = int(stdin.readline().strip())
cards = list(map(int, stdin.readline().strip().split(' ')))
temp = [0] * len(cards)
M = int(stdin.readline().strip())
nums = list(map(int, stdin.readline().strip().split(' ')))

def merge(start_index, end_index):
	global cards, temp
	mid = int((start_index + end_index) / 2)
	left_index = start_index
	right_index = mid
	idx = start_index
	while idx < end_index:
		if left_index == mid:
			temp[idx] = cards[right_index]
			right_index += 1
			idx += 1
		elif right_index == end_index:
			temp[idx] = cards[left_index]
			left_index += 1
			idx += 1
		elif cards[left_index] < cards[right_index]:
			temp[idx] = cards[left_index]
			left_index += 1
			idx += 1
		else:
			temp[idx] = cards[right_index]
			right_index += 1
			idx += 1
	for i in range(start_index, end_index):
		cards[i] = temp[i]

def merge_sort(start_index, end_index):
	if end_index - start_index < 2:
		return
	mid = int((start_index + end_index)/2)
	merge_sort(start_index, mid)
	merge_sort(mid, end_index)
	merge(start_index, end_index)

def merge_search_max(start_index, end_index, num):
	global max_num, cards
	while start_index < end_index:
		mid = int((start_index + end_index) / 2)
		if cards[mid] > num:
			end_index = mid
		else:
			start_index = mid + 1
	max_num = start_index

def merge_search_min(start_index, end_index, num):
	global min_num, cards
	while start_index < end_index:
		mid = int((start_index + end_index) / 2)
		if cards[mid] >= num:
			end_index = mid
		else:
			start_index = mid+1
	min_num = start_index

merge_sort(0, len(cards))
result = ''
for i in range(len(nums)):
	max_num = -1
	min_num = len(cards)+1
	merge_search_max(0, len(cards), nums[i])
	merge_search_min(0, len(cards), nums[i])
	if max_num == -1 and min_num == len(cards)+1:
		result += str(0) + ' '
	else:
		result += str(max_num - min_num) + ' '
print(result)

