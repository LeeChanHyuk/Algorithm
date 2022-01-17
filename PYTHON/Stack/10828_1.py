from sys import stdin

N = int(stdin.readline().strip())
stack = []
for i in range(N):
    command = stdin.readline().strip()
    if command[0:2] == 'pu':
        _, num = command.split(' ')
        num = int(num)
        stack.append(num)
    elif command[0:2] == 'po':
        if len(stack)>0:
            print(stack.pop())
        else:
            print('-1')
    elif command[0:2] == 'si':
        print(len(stack))
    elif command[0:2] == 'em':
        if len(stack) == 0:
            print('1')
        else:
            print('0')
    elif command[0:2] == 'to':
        if len(stack)>0:
            print(stack[len(stack)-1])
        else:
            print('-1')