from sys import stdin
command_num = int(stdin.readline().strip())
top = list(map(int,stdin.readline().split()))
top.reverse()
result = []
pop_lists = []
for i in range(len(top)):
    num = top.pop()
    # 새로 들어온 애가 기존애 있는 애들보다 같거나 더 큰지 / 더 작으면 걔를 넣는거고.
    while 1:
        if len(pop_lists) == 0:
            result.append(0)
            pop_lists.append((i+1, num))
            break
        elif num >= pop_lists[len(pop_lists)-1][1]:
            pop_lists.pop()
        else:
            result.append(pop_lists[len(pop_lists)-1][0])
            pop_lists.append((i+1,num))
            break
print(' '.join(map(str,result[0:])))