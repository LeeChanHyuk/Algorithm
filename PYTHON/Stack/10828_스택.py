from sys import stdin
command_num = int(stdin.readline().strip())
stack=[]
for i in range(command_num):
    line = stdin.readline().strip()
    if line[0:2] == 'pu':
        _, num = line.split()
        stack.append(num)
    elif line[0:2] == 'po':
        if stack:
            print(stack.pop())
        else:
            print('-1')
    elif line[0:2] == 'si':
        print(len(stack))
    elif line[0:2] == 'em':
        if stack:
            print('0')
        else:
            print('1')
    else: # top
        if stack:
            print(stack[-1])
        else:
            print('-1')