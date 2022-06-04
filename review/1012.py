from sys import stdin
N = int(stdin.readline().strip())
for case in range(N):
    caabage = []
    W, H, K = map(int, stdin.readline().strip().split(' '))
    board = [[0 for i in range(W)]for j in range(H)]
    via = [[0 for i in range(W)]for j in range(H)]
    for k in range(K):
        j, i = map(int, stdin.readline().strip().split(' '))
        caabage.append((i,j))
        board[i][j] += 1
    queue = []
    ans = 0
    for (i, j) in caabage:
        if via[i][j] >= 1:
            continue
        ans += 1
        queue.append((i,j))
        via[i][j] = 1
        while len(queue) > 0:
            i_2, j_2 = queue.pop(0)
            if j_2+1 < W and board[i_2][j_2+1] == 1 and via[i_2][j_2+1] == 0:
                queue.append((i_2, j_2+1))
                via[i_2][j_2+1] = 1
            if i_2+1 < H and board[i_2+1][j_2] == 1 and via[i_2+1][j_2] == 0:
                queue.append((i_2+1, j_2))
                via[i_2+1][j_2] = 1
            if j_2-1 >= 0 and board[i_2][j_2-1] == 1 and via[i_2][j_2-1] == 0:
                queue.append((i_2, j_2-1))
                via[i_2][j_2-1] = 1
            if i_2-1 >= 0 and board[i_2-1][j_2] == 1 and via[i_2-1][j_2] == 0:
                queue.append((i_2-1, j_2))
                via[i_2-1][j_2] = 1
    print(ans)