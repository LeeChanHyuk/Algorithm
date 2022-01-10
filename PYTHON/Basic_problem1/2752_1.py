from sys import stdin

a, b, c = map(int, stdin.readline().strip().split(' '))
if a<b and a<c:
    if b<c:
        print(a, b, c, sep=' ')
    else:
        print(a, c, b, sep =' ')
if b<a and b<c:
    if a<c:
        print(b, a, c, sep=' ')
    else:
        print(b, c, a, sep=' ')
if c<a and c<b:
    if a<b:
        print(c, a, b, sep=' ')
    else:
        print(c, b, a, sep=' ')