from sys import stdin

N = int(stdin.readline().strip())

nums = list(map(int, stdin.readline().strip().split(' ')))

result = 0
for num in nums:
    i = 2
    success = False
    while i*i <= num:
        if num % i == 0:
            success = True
            break
        i += 1
    if not success and num != 1:
        result += 1
print(result)
