from sys import stdin

def common_num(A, B):
    if A == 0:
        return B
    return common_num(B%A, A)

def least_num(A, B):
    return A / common_num(A, B) * B

A, B = map(int, stdin.readline().strip().split(' '))
print(int(common_num(A, B)))
print(int(least_num(A, B)))