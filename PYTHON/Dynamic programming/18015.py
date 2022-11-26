from sys import stdin

N, B = map(int, stdin.readline().strip().split(' '))

D = [[[[0 for l in range(2)] for k in range(2)] for j in range(B)] for i in range(N+1)]

# D[layer][number][0][B-1] = 해당 layer의 number

for i in range(1, B):
    if i == B-1:
        D[1][i][0][1] = 1
    else:
        D[1][i][0][0] = 1

for i in range(2, N+1):
    for j in range(B):
        if j == 0:
            D[i][j][1][0] = (D[i-1][1][1][0] + D[i-1][1][0][0])
            D[i][j][1][1] = (D[i-1][1][1][1] + D[i-1][1][0][1])
        elif j == B-1:
            D[i][j][0][1] = (D[i-1][B-2][0][1] + D[i-1][B-2][0][0])
            D[i][j][1][1] = (D[i-1][B-2][1][1] + D[i-1][B-2][1][0])
        else:
            D[i][j][0][0] = (D[i-1][j-1][0][0] + D[i-1][j+1][0][0])
            D[i][j][0][1] = (D[i-1][j-1][0][1] + D[i-1][j+1][0][1])
            D[i][j][1][0] = (D[i-1][j-1][1][0] + D[i-1][j+1][1][0])
            D[i][j][1][1] = (D[i-1][j-1][1][1] + D[i-1][j+1][1][1])
        if j % 20 == 0:
            D[i][j][0][0] = D[i][j][0][0] % 1000000000
            D[i][j][0][1] = D[i][j][0][1] % 1000000000
            D[i][j][1][0] = D[i][j][1][0] % 1000000000
            D[i][j][1][1] = D[i][j][1][1] % 1000000000

sum = 0
for i in range(B):  
    sum += (D[N][i][1][1])
print(sum % 1000000000)

