from sys import stdin
from copy import deepcopy

N, M = map(int, stdin.readline().strip().split(' '))

house = list()
chicken_house = list()
result  = 20000

for i in range(N):
    inputs = list(map(int, stdin.readline().strip().split(' ')))
    for j in range(N):
        if inputs[j] == 1:
            house.append([i, j])
        elif inputs[j] == 2:
            chicken_house.append([i, j])


def back_tracking(k, selected_chicken_house, prev_i):
    global house, chicken_house, N, M, result
    if k == M:
        total_min = 0
        for i in range(len(house)):
            min = 3000
            for j in range(M):
                distance = abs(house[i][0] - selected_chicken_house[j][0]) + abs(house[i][1] - selected_chicken_house[j][1])
                if distance < min:
                    min = distance
            total_min += min
        if total_min < result:
            result = total_min
    else:
        for i in range(prev_i, len(chicken_house)):
            temp_chicken_house = deepcopy(selected_chicken_house)
            temp_chicken_house.append(chicken_house[i])
            back_tracking(k+1, temp_chicken_house, i + 1)

back_tracking(0, [], 0)
print(result)
        
            

