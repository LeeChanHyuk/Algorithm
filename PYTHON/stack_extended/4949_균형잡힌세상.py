from sys import stdin

stack = []
while 1:
    command = stdin.readline().rstrip()
    if len(command) == 1 and command == '.':
        break
    for str in command:
        if str == '[' or str == '(':
            stack.append(str)
        elif str == ')':
            if len(stack) == 0:
                stack.append('(')
                break
            elif stack[-1] == '(':
                stack.pop()
            else:
                stack.append('(')
                break
        elif str == ']':
            if len(stack) == 0:
                stack.append('[')
                break
            elif stack[-1] == '[':
                stack.pop()
            else:
                stack.append('[')
                break
    if len(stack) == 0:
        print('yes')
    else:
        print('no')
    stack.clear()