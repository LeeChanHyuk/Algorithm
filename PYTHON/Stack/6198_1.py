from sys import stdin
stack = []
sum = 0
N = int(stdin.readline().strip())
for i in range(N):
    height = int(stdin.readline().strip())
    while stack and height >= stack[-1]:
        stack.pop()
    sum += len(stack)
    stack.append(height)
print(sum)