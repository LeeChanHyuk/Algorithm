from sys import stdin
number = input()
number_count = [0] * 10
for i in range(10):
    number_count[i] += number.count(chr(i+48))
number_count[6] += number_count[9]
number_count[6] += 1
number_count[6] /= 2
number_count[9] = 0
print(int(max(number_count)))