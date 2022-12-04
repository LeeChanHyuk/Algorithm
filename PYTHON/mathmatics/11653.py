from sys import stdin

N = int(stdin.readline().strip())
original_n = N

for i in range(2, original_n+1):
    if N == 1:
        break
    while N % i == 0:
        print(i)
        N /= i
