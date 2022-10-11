from sys import stdin

D = [0] * 41
D[0] = (1, 0)
D[1] = (0, 1)
D[2] = (1, 1)
for i in range(3, 41):
    D[i] = (D[i-2][0] + D[i-1][0], D[i-2][1] + D[i-1][1])

test_case = int(stdin.readline().strip())
for i in range(test_case):
    number= int(stdin.readline().strip())
    print(str(D[number][0]), str(D[number][1]))
