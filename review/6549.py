from sys import stdin
stack = list()
while 1:
	arr = list(map(int, stdin.readline().strip().split(' ')))
	max_val = 0
	if arr[0] == 0:
		break
	for i in range(1, arr[0]+1):
		width = 0
		while len(stack) != 0 and stack[-1][0] > arr[i]:
			width += stack[-1][1]
			max_val = max(max_val, width * stack[-1][0])
			stack.pop()
		width += 1
		stack.append((arr[i], width))
	width = 0
	while len(stack) != 0:
		width += stack[-1][1]
		max_val = max(max_val, width * stack[-1][0])
		stack.pop()
	print(max_val)