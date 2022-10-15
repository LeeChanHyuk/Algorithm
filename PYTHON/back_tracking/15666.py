from sys import stdin

N, M = map(int, stdin.readline().strip().split(' '))
arr = list(map(int, stdin.readline().strip().split(' ')))
arr.sort()
result = []
result_dict = dict()

def back_tracking(k, prev_i):
    if k == M:
        line = ''
        for i in range(M):
            line += str(result[i]) + ' '
        if line not in result_dict.keys():
            result_dict[line] = 0
            print(line)
    else:
        for i in range(N):
            if i >= prev_i:
                result.append(arr[i])
                back_tracking(k+1, i)
                result.pop()
back_tracking(0, 0)





