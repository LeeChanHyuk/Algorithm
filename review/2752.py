from sys import stdin

numbers = list(map(int, stdin.readline().strip().split(' ')))
numbers = sorted(numbers)
print(numbers[0], numbers[1], numbers[2])