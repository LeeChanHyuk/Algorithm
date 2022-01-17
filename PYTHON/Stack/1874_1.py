from sys import stdin
N = int(stdin.readline().strip())
stack = []
nums = []
commands = []
for i in range(N):
    num = int(stdin.readline().strip())
    nums.append(num)
count = 0
success = True
for i in nums:
    if success:
        while 1:
            if count < i:
                count += 1
                commands.append('+')
                stack.append(count)
            elif len(stack)>0 and stack[-1] == i:
                stack.pop()
                commands.append('-')
                break
            else:
                success = False
                break
if not success:
    print('NO')
else:
    print('\n'.join(commands))