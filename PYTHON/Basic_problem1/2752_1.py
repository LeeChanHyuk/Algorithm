from sys import stdin

a, b, c = map(int, stdin.readline().strip().split(' '))
if b<a:
    if b<c:
        print(c, b, a, sep=' ')
