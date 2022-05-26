from sys import stdin
numbers = input()
number_count_array = [0, 0, 0, 0, 0, 0, 0, 0, 0]
for i in range(len(numbers)):
	number = int(numbers[i])
	if number == 9:
		number = 6
	number_count_array[number] += 1
if number_count_array[6] % 2 == 0:
	number_count_array[6] /= 2
else:
	number_count_array[6] /= 2
	number_count_array[6] += 1
max_num = max(number_count_array)
print(max(int(max_num), 1))