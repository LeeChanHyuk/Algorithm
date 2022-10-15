from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
arr = []
isused = []
result = []
for i in range(1, N+1):
    arr.append(i)
    isused.append(0)

def back_tracking(k):
    if k == M:
        for i in range(k):
            print(result[i], end=' ')
        print()
    else:
        for i in range(N):
            if not isused[i]:
                isused[i] = 1
                result.append(arr[i])
                back_tracking(k+1)
                isused[i] = 0
                result.pop()
back_tracking(0)
