from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
arr = list(map(int, stdin.readline().strip().split(' ')))
arr.sort()
isused = [0] * len(arr)
result = []
result_dict = dict()

def back_tracking(k):
    if k == M:
        line = ''
        for i in range(k):
            line += str(result[i])+' '
        if line not in result_dict.keys():
            result_dict[line] = 0
            print(line[0:-1])
    else:
        for i in range(N):
            if isused[i] == 0:
                result.append(arr[i])
                isused[i] = 1
                back_tracking(k+1)
                result.pop()
                isused[i] = 0
back_tracking(0)