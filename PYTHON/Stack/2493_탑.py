from sys import stdin
command_num = int(stdin.readline().strip())
top = list(map(int,stdin.readline().strip().split()))
result = [0] * len(top)
pop_lists = []
for i in range(len(top)):
    num = top.pop()
    for j in range(len(pop_lists), -1):
        if pop_val[j-1] >= num:



