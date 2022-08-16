from sys import stdin

N = int(stdin.readline())
board = []
for i in range(N):
    board.append(list(map(int, stdin.readline().strip().split())))

color_paper = [0, 0]
def recursive(N, start_point, color_paper):
    if N == 2:
        part = [0, 0, 0, 0]
        part[0] = board[start_point[0]][start_point[1]]
        part[1] = board[start_point[0]][start_point[1] + 1]
        part[2] = board[start_point[0] + 1][start_point[1]]
        part[3] = board[start_point[0] + 1][start_point[1] + 1]
        if part[0] == part[1] == part[2] == part[3] == 0:
            return 0
        elif part[0] == part[1] == part[2] == part[3] == 1:
            return 1
        else:
            for i in range(4):
                color_paper[part[i]] += 1
            return -1
    else:
        part = [0, 0, 0, 0]
        width = int(N/2)
        part[0] = recursive(width, (start_point[0], start_point[1]), color_paper)
        part[1] = recursive(width, (start_point[0], start_point[1] + width), color_paper)
        part[2] = recursive(width, (start_point[0] + width, start_point[1]), color_paper)
        part[3] = recursive(width, (start_point[0] + width, start_point[1] + width), color_paper)
        if part[0] == part[1] == part[2] == part[3] == 0:
            return 0
        elif part[0] == part[1] == part[2] == part[3] == 1:
            return 1
        else:
            for i in range(4):
                if part[i] == -1:
                    continue
                color_paper[part[i]] += 1
            return -1
result = recursive(N, (0, 0), color_paper)
if result != -1:
    color_paper[result] += 1
print(color_paper[0])
print(color_paper[1])



