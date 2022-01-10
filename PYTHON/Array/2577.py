from sys import stdin
a = 1
for i in range(3):
    a *= int(stdin.readline().strip())
a = str(a)
for i in range(10):
    print(a.count(chr(i + 48)))
