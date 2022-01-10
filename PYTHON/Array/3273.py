from sys import stdin
n = int(stdin.readline().strip())
numbers_array = list(map(int, stdin.readline().strip().split(' ')))
x = int(stdin.readline().strip())
number_array = [0] * 2000000
for index, i in enumerate(numbers_array):
    number_array[i] += 1
    numbers_array[index] = x - numbers_array[index]
count = 0
for i in numbers_array:
    if number_array[i] > 0:
        count += 1
print(int(count/2))