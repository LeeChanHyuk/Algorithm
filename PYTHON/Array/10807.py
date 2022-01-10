from sys import stdin
N = int(stdin.readline().strip())
array = list(map(int, stdin.readline().strip().split(' ')))
x = int(stdin.readline().strip())
count = 0
for i in range(len(array)):
    if array[i] == x:
        count += 1
print(count)