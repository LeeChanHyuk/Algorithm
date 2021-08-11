from sys import stdin
number = stdin.readline().strip()
number_list = [0] * 9
for i in range(len(number)):
    if int(number[i]) == 9:
        number_list[6] += 1
        continue
    number_list[int(number[i])] += 1
number_list[6] /= 2
max_num = max(number_list)
if max_num > int(max_num):
    print(int(max_num) + 1)
else:
    print(int(max_num))