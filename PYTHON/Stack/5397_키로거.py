from sys import stdin
command_num = int(stdin.readline().strip())
for i in range(command_num):
    line = list(stdin.readline().strip())
    stack1 = []
    stack2 = []
    for word in line:
        if word in "><-":
            if word == '<' and stack1:
                stack2.append(stack1.pop())
            elif word == '>' and stack2:
                if len(stack2) != 0:
                    stack1.append(stack2.pop())
            elif word == '-' and stack1:
                stack1.pop()
        else:
            stack1.append(word)
    print(''.join(stack1)+''.join(stack2[::-1]))