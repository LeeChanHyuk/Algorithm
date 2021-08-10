from sys import stdin
stack_right = []
first_sentence = stdin.readline().strip()
stack_left = list(first_sentence)
command_num = int(stdin.readline())
for i in range(command_num):
    command = stdin.readline().strip().split()
    str = ""
    if command[0] == 'P':
        str = command[1]
        stack_left.append(str)
    elif command[0] == 'L' and len(stack_left) != 0:
        stack_right.append(stack_left.pop())
    elif command[0] == 'D' and len(stack_right) != 0:
        stack_left.append(stack_right.pop())
    elif command[0] == 'B' and len(stack_left) != 0:
        stack_left.pop()
print(''.join(stack_left),end='')
print(''.join(stack_right[::-1]),end='')

# 1. input() 보다는 stdin.readline()을 쓰자.
# 2. 빈 리스트에 append로 추가하는 것 보다는 입력 받을 개수만큼 초기화된 인덱스를 이용해서 접근, 그 위치에 직접 입력받자.
# 3. 줄 바꿈을 할때는 문자열 + '\' 을 통해서 줄 바꿈을 진행하자



