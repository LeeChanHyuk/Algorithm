from sys import stdin
### 쇠막대기
line = stdin.readline().strip()
stack = []
last_code=""
num = 0
for i in range(len(line)):
    code = line[i]
    if code == '(':
        stack.append(code)
        num += 1
    elif code == ')':
        if last_code == '(':
            num -= 1
            stack.pop()
            num += len(stack)
        else:
            stack.pop()
    last_code = code
print(num)

