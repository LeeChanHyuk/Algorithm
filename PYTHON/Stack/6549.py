from sys import stdin
max = 0
while 1:
    inputs = list(map(int, stdin.readline().strip().split(' ')))
    if len(inputs) == 1:
        break
    stack = []
    for i in range(1, inputs[0]):
        num = inputs[i]
        if not stack:
            stack.append([num, num])
            max = num
        elif num < stack[-1][0]:
            last_block_area = num
            while stack and num<stack[-1][0]:
                stack.pop()
                last_block_area += num
            stack.append([num, last_block_area])
            if last_block_area > max:
                max = last_block_area
        if num > stack[-1][0]:
            for j in range(len(stack)):
                stack[j][1] += stack[j][0]
                if stack[j][1] > max:
                    max = stack[j][1]
            stack.append([num, num])
        elif num == stack[-1][0]:
            for j in range(len(stack)):
                stack[j][1] += stack[j][0]
                if stack[j][1] > max:
                    max = stack[j][1]
    print(max)