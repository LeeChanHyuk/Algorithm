from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
arr = list(map(int, stdin.readline().strip().split(' ')))
arr.sort()
result = []
result_dict = dict()

def back_tracking(k):
    if k == M:
        line = ''
        for i in range(k):
            line += str(result[i]) + ' '
        if line not in result_dict.keys():
            print(line)
            result_dict[line] = 0
    else:
        for i in range(N):
            result.append(arr[i])
            back_tracking(k+1)
            result.pop()
back_tracking(0)
