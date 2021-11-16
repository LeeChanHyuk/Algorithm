import os
import sys

stack = []

number_count = int(sys.stdin.readline())
top = -1
total = 0
for i in range(number_count):
    num = int(sys.stdin.readline())
    if len(stack) == 0:
        stack.append(num)
        top += 1
    elif stack[top]>num:
        stack.append(num)
        total += len(stack)-1
        top += 1
    else:
        while len(stack)>0 and stack[top]<num:
            stack.pop()
            top -= 1
        stack.append(num)
        total += len(stack) - 1
        top += 1
print(total)