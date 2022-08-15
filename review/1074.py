from re import A
from sys import stdin
from tracemalloc import start

N, r, c = map(int, stdin.readline().strip().split(' '))
width = int(2 ** N)

def recursive(width, start_point, start_num, r, c):
    if width == 1:
        if start_point[0] == r and start_point[1] == c:
            print(start_num)
    else:
        new_width = int(width/2)
        if r >= start_point[0] and r < start_point[0] + new_width and c >= start_point[1] and c < start_point[1] + new_width:
            recursive(new_width, start_point, start_num, r, c)
        elif r >= start_point[0] and r < start_point[0] + new_width and c >= start_point[1] + new_width and c < start_point[1] + (new_width * 2):
            recursive(new_width, (start_point[0], start_point[1] + new_width), start_num + int((width ** 2) / 4 ), r, c)
        elif r >= start_point[0] + new_width and r < start_point[0] + (new_width * 2) and c >= start_point[1] and c < start_point[1] + new_width:
            recursive(new_width, (start_point[0] + new_width, start_point[1]), start_num + int((width ** 2) / 4 * 2), r, c)
        else:
            recursive(new_width, (start_point[0] + new_width, start_point[1] + new_width), start_num + int((width ** 2) / 4 * 3), r, c)

recursive(width, (0, 0), 0, r, c)