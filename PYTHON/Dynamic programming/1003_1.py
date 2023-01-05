from sys import stdin

test_case = int(stdin.readline().strip())
D = [0, 0] * 41
D[0] = [1, 0]
D[1] = [0, 1]
for i in range(test_case):
    N = int(stdin.readline().strip())
    for i in range(2, N+1):
        D[i] = [D[i-1][0] + D[i-2][0], D[i-1][1] + D[i-2][1]]
    print(D[N][0], D[N][1])
