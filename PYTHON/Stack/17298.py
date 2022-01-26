from sys import stdin
N = int(stdin.readline().strip())
nums = list(map(int, stdin.readline().strip().split(' ')))
nge = [-1] * len(nums)
stack = []
for index, i in enumerate(nums):
    if len(stack) == 0:
        stack.append((index, i))
    else:
        while stack and stack[-1][1] < i:
            stack_index, num = stack.pop()
            nge[stack_index] = i
        stack.append((index, i))
print(' '.join(map(str,nge[0:])))