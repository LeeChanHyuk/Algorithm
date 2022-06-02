from sys import stdin
stack = list()
N = int(stdin.readline().strip())
sum = 0
for i in range(N):
	building_height = int(stdin.readline().strip())
	if len(stack)>0:
		while len(stack)>0:
			if stack[len(stack)-1] <= building_height:
				stack.pop()
			else:
				break
		sum += len(stack)
		stack.append(building_height)
	else:
		stack.append(building_height)
print(sum)