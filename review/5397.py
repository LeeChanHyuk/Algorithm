from audioop import reverse
from sys import stdin
N = int(stdin.readline().strip())
def process(char, left_list, right_list):
	left_len = len(left_list)
	right_len = len(right_list)
	if char == '<':
		if left_len>0:
			right_list.append(left_list.pop(left_len-1))
	elif char == '>':
		if right_len>0:
			left_list.append(right_list.pop(right_len-1))
	elif char == '-':
		if left_len>0:
			left_list.pop(left_len-1)
	else:
		left_list.append(char)
	return left_list, right_list
for i in range(N):
	left_list = []
	right_list = []
	str = stdin.readline().strip()
	for char in str:
		left_list, right_list = process(char, left_list, right_list)
	print(''.join(left_list)+''.join(right_list[::-1]))