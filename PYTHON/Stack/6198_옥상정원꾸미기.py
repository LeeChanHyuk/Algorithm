from sys import stdin
building_num = int(stdin.readline().strip())
stack = []
result = 0
for i in range(building_num):
    height = int(stdin.readline().strip())
    while 1:
        if len(stack) == 0:
            stack.append(height)
            break
        elif height < stack[len(stack)-1]:
            result += len(stack)
            stack.append(height)
            break
        elif height >= stack[len(stack)-1]:
            stack.pop()
print(result)
