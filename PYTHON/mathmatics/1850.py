from sys import stdin

A, B = map(int, stdin.readline().strip().split(' '))

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)
num = gcd(A, B)
for i in range(num):
    print('1', end='')