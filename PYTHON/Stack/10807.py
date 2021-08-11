from sys import stdin
command_num = int(stdin.readline().strip())
num_lists = list(map(int,stdin.readline().strip().split()))
find_num = int(stdin.readline().strip())
count=0
for i in range(len(num_lists)):
    if num_lists.pop() == find_num:
       count += 1
print(count)