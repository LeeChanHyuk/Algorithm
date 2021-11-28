import os
import sys
error = 0
while 1:
    stack = []
    input_sequence = sys.stdin.readline().strip()
    if input_sequence == None:
        break
    for i in len(input_sequence):
        str = input_sequence[i]
        str_len = len(str)
        if str == '[' or str == '(':
            stack.append(str)
        elif str == ']':
            if stack[len(stack)-1] == '[':
                stack.pop()
            else:
                error = 1
                break
        elif str == ')':
            if stack[len(stack)-1] == '(':
                stack.pop()
            else:
                error = 1
                break
    if error == 1:
        print('no')
    else:
        print('yes')
    error = 0
    stack.clear()