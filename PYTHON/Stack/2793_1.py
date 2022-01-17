from sys import stdin
N = int(stdin.readline().strip())
nums = list(map(int, stdin.readline().strip().split(' ')))
stack = []
results = []
index = []
total = 0
for i in nums:
    total += 1
    while 1:
        if len(stack) == 0:
            results.append('0')
            stack.append(i)
            index.append(total)
            break
        elif stack[-1] < i:
            stack.pop()
            index.pop()
        elif stack[-1] > i:
            results.append(str(index[-1]))
            stack.append(i)
            index.append(total)
            break
print(' '.join(results))