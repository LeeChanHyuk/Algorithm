from sys import stdin
command_num = int(stdin.readline().strip())
# 결국 pop 시킨애를 다시 불러오라고하면 안되는 것.
pointer = 0
num_list = [-1] * command_num
operator_list = []
stopped=False
for i in range(command_num):
    num = int(stdin.readline().strip())
    if pointer < num:
        for j in range(pointer, num):
            if num_list[j] == -1:
                num_list[j] = 1
                operator_list.append('+')
        pointer = num-1
        if num_list[num-1] == 1:
            num_list[num-1] -= 1
            operator_list.append(('-'))
        else:
            print("NO")
            stopped=True
            break
    elif pointer == num:
        if num_list[num-1] == 1:
            num_list[num-1] -= 1
            operator_list.append('-')
        else:
            print("NO")
            stopped=True
            break
        pointer -= 1
    else: # pointer > num
        for j in range(pointer, num-1, -1):
            if num_list[j] == 1:
                num_list[j] -= 1
                operator_list.append('-')
        if num_list[num-1] == 1:
            num_list[num-1] -= 1
            operator_list.append('-')
        else:
            print("NO")
            stopped=True
            break
        pointer = num-1
if stopped==False:
    for i in range(len(operator_list)):
        print(operator_list[i])
