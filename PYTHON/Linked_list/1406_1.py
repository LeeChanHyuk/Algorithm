from sys import stdin

input = stdin.readline().strip()
N = int(stdin.readline().strip())
left_list = []
right_list=[]
for i in input:
    left_list.append(i)
for i in range(N):
    # Input
    command = stdin.readline().strip()
    if command[0] == 'P':
        command, alphabet = command.split(' ')
    
    # Processing
    if command == 'L' and len(left_list)>0:
        right_list.append(left_list.pop())
    elif command == 'D' and len(right_list)>0:
        left_list.append(right_list.pop())
    elif command == 'B' and len(left_list)>0:
        left_list.pop()
    elif command == 'P':
        left_list.append(alphabet)
right_list.reverse()
for i in left_list:
    print(i, end='')
for j in right_list:
    print(j, end='')