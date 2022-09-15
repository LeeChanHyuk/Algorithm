from sys import stdin

def get_input():
    x = []
    x.append(stdin.readline().strip())
    x.append(stdin.readline().strip())
    x.append(stdin.readline().strip())
    x.append(stdin.readline().strip())
    test_case = int(stdin.readline().strip())
    order = []
    for i in range(test_case):
        order.append(list(map(int, stdin.readline().strip().split(' '))))
    return x, order

def check(x_pivot):
    for i in range(4):
        for j in range(2):
            if x_pivot[i][j] == -1:
                x_pivot[i][j] = 7
            elif x_pivot[i][j] == 8:
                x_pivot[i][j] = 0

def recursive(x_pivot, x, num, direction, first, counter_part_pivot, left):
    if first:
        if num != 0:
            x_pivot[num][0] -= direction
        if num != 3:
            x_pivot[num][1] -= direction
        check(x_pivot)
        if num != 3:
            recursive(x_pivot, x, num+1, -direction, False, (x_pivot[num][1] + direction + 8)%8, 1)
        if num != 0:
            recursive(x_pivot, x, num-1, -direction, False, (x_pivot[num][0] + direction + 8) % 8, 0)
    else:
        if left:
            if x[num-1][counter_part_pivot] != x[num][x_pivot[num][0]]:
                x_pivot[num][0] -= direction
                check(x_pivot)
                if num != 3:
                    x_pivot[num][1] -= direction
                    check(x_pivot)
                    recursive(x_pivot, x, num+1, -direction, False, (x_pivot[num][1] + direction + 8) % 8, 1)
        else:
            if x[num-1][counter_part_pivot] != x[num][x_pivot[num][1]]:
                x_pivot[num][1] -= direction
                check(x_pivot)
                if num != 0:
                    x_pivot[num][0] -= direction
                    check(x_pivot)
                    recursive(x_pivot, x, num-1, -direction, False, x_pivot[num][0] + direction, 0)


x, order = get_input()
x_pivot = [ #[left_pivot, right_pivot]
    [-2, 2],
    [6, 2], 
    [6, 2],
    [6, -2]
]

for [num, direction] in order:
    num -= 1
    recursive(x_pivot, x, num, direction, True, 0, 0)

result = 0
for i in range(4):
    pivot = (x_pivot[i][1] - 2 + 8) % 8
    if x[i][pivot] == '1':
        result += (2 ** i)
print(result)





