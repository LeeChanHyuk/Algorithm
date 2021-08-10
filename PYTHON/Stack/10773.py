from sys import stdin
command_num = int(stdin.readline())
nums = []
for i in range(command_num):
    num = int(stdin.readline())
    if num == 0:
        nums.pop()
    else:
        nums.append(num)

print(sum(nums))