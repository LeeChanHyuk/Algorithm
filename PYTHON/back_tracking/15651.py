from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
result = []

def back_tracking(k):
    if k == M:
        for i in range(k):
            print(result[i], end=' ')
        print()
    else:
        for i in range(1, N+1):
            result.append(i)
            back_tracking(k+1)
            result.pop()
back_tracking(0)
