from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
result = []

def back_tracking(k, prev_i):
    if k == M:
        for i in range(k):
            print(result[i], end=' ')
        print()
    else:
        for i in range(1, N+1):
            if i > prev_i:
                result.append(i)
                back_tracking(k+1, i)
                result.pop()
back_tracking(0, 0)

