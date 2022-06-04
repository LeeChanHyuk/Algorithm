from sys import stdin
while 1:
    stack = []
    line = stdin.readline()
    line = line[0: len(line)-1]
    if len(line) == 1 and line[0] == '.':
        break
    for char in line:
        if char == '[' or char == '(':
            stack.append(char)
        elif char == ']' and len(stack) > 0 and stack[-1] == '[':
            stack.pop()
        elif char == ')' and len(stack) > 0 and stack[-1] == '(':
            stack.pop()
        elif char == ']' and ((len(stack) > 0 and stack[-1] != '[') or len(stack) == 0):
            stack.append(']')
            break
        elif char == ')' and ((len(stack) > 0 and stack[-1] != '(') or len(stack) == 0):
            stack.append(')')
            break
    if len(stack) == 0:
        print('yes')
    else:
        print('no')