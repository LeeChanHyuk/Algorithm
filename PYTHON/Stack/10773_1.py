from sys import stdin
stack = []
N = int(stdin.readline().strip())
for i in range(N):
    command = int(stdin.readline().strip())
    if command != 0:
        stack.append(command)
    else:
        stack.pop()
sum = 0
for i in stack:
    sum += i
print(sum)