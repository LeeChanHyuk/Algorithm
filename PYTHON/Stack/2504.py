from sys import stdin
line = stdin.readline().strip()
stack=[]
for i in range(len(line)):
    str = line[i]
    if str == '(' or str == '[':
        stack.append(str)
    elif str == ')':
        if len(stack) == 0:
            print(0)
            break
        else:
            pop_val = stack.pop()
        if pop_val == '(':
            if len(stack) == 0:
                stack.append(2)
            elif type(stack[len(stack)-1]) is int:
                stack[len(stack)-1] += 2
            else:
                stack.append(2)
        elif type(pop_val) is int:
            if len(stack) == 0:
                print(0)
                break
            elif stack.pop() == '(':
                if len(stack) == 0:
                    stack.append(pop_val * 2)
                elif type(stack[len(stack)-1]) is int:
                    stack[len(stack)-1] += (pop_val * 2)
                else:
                    stack.append(pop_val*2)
            else:
                print(0)
                break
        else:
            print(0)
            break
    else:
        if len(stack) == 0:
            print(0)
            break
        else:
            pop_val = stack.pop()
        if pop_val == '[':
            if len(stack) == 0:
                stack.append(3)
            elif type(stack[len(stack)-1]) is int:
                stack[len(stack)-1] += 3
            else:
                stack.append(3)
        elif type(pop_val) is int:
            if len(stack) == 0:
                print(0)
                break
            elif stack.pop() == '[':
                if len(stack) == 0:
                    stack.append(pop_val * 3)
                elif type(stack[len(stack)-1]) is int:
                    stack[len(stack)-1] += (pop_val*3)
                else:
                    stack.append(pop_val*3)
            else:
                print(0)
                break
        else:
            print(0)
            break
    if i == len(line)-1:
        print(stack[0])