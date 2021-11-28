import os
import sys
input_line = sys.stdin.readline().strip()
stack = []
total = 0
last = '-'
for str in input_line:
    if str == '(':
        stack.append('(')
    elif str == ')':
        stack.pop()
        if last == '(':
            total += len(stack)
        else:
            total += 1
    last = str
print(total)
