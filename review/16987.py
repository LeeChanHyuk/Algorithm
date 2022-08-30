from sys import stdin

test_case = int(stdin.readline().strip())
eggs = []
for i in range(test_case):
    protect, weight = map(int, stdin.readline().strip().split(' '))
    eggs.append([protect, weight])

max_brack_num = 0

def back_tracking(k, temp_eggs):
    global max_brack_num
    if k == len(temp_eggs):
        break_egg_num = 0
        for i in range(len(temp_eggs)):
            if temp_eggs[i][0] <= 0:
                break_egg_num += 1
        if break_egg_num > max_brack_num:
            max_brack_num = break_egg_num
    else:
        current_egg = temp_eggs[k]
        if current_egg[0] > 0:
            for i in range(len(temp_eggs)):
                if k==len(temp_eggs)-1 and i==k:
                    back_tracking(k+1, temp_eggs)
                if i == k:
                    continue
                if temp_eggs[i][0] <= 0:
                    continue
                temp_eggs[k][0] -= temp_eggs[i][1]
                temp_eggs[i][0] -= temp_eggs[k][1]
                back_tracking(k+1, temp_eggs)
                temp_eggs[k][0] += temp_eggs[i][1]
                temp_eggs[i][0] += temp_eggs[k][1]
        else:
            back_tracking(k+1, temp_eggs)
back_tracking(0, eggs)
print(max_brack_num)





