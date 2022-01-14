from sys import stdin
N = int(stdin.readline().strip())
for i in range(N):
    left_list = []
    right_list = []
    input = stdin.readline().strip()
    for j in input:
        if j == '<':
            if len(left_list) > 0:
                right_list.append(left_list.pop())
        elif j == '>':
            if len(right_list) > 0:
                left_list.append(right_list.pop())
        elif j == '-':
            if len(left_list) > 0:
                left_list.pop()
        else:
            left_list.append(j)
    for a in left_list:
        print(a, end='')
    right_list.reverse()
    for a in right_list:
        print(a, end='')
    print()