from sys import stdin


def back_tracking(sum_number, S, k, prev_i):
    global sum_array, num_array, result
    if k == sum_number:
        sum = 0
        for i in range(k):
            sum += sum_array[i]
        if sum == S:
            result += 1
    else:
        for i in range(prev_i, len(num_array)):
            sum_array[k] = num_array[i]
            back_tracking(sum_number, S, k+1, i+1)

N, S = map(int, stdin.readline().strip().split(' '))
num_array = list(map(int, stdin.readline().strip().split(' ')))
result = 0
for i in range(1, N+1):
    sum_array = [0] * i
    back_tracking(i, S, 0, 0)
print(result)




