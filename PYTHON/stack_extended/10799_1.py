import os
import sys
input_line = sys.stdin.readline().strip()
stack = []
total = 0
for str in input_line:
    if str == '(':
        stack.append('(')
        total += 1
    elif str == ')':
        stack.pop()
        if last == '(':
            total += len(stack) -1
    last = str
print(total)
