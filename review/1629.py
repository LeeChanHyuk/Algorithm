from sys import stdin
a, b, c = map(int, stdin.readline().strip().split(' '))
def pow(a, b, c):
    if b == 1:
        return a % c
    val = (pow(a, int(b/2), c) * pow(a, int(b/2), c)) % c
    if b%2 == 1:
        val = (val * a) % c
    return val
print(pow(a, b, c))