from sys import stdin
N = int(stdin.readline().strip())
stack = []
count = 0
same = 0
for i in range(N):
    num = int(stdin.readline().strip())
    while stack and stack[-1][0] < num:
        count += (stack[-1][1] + 1)
        stack.pop()
    if stack and stack[-1][0] == num:
        last_same = stack[-1][1] # 마지막 숫자랑 같은 숫자의 개수
        if len(stack) > (last_same + 1):
            count += (last_same + 2)
        else:
            count += (last_same + 1)
        stack[-1][1] += 1
        continue
    if stack:
        count += 1
    stack.append([num, 0])
print(count)