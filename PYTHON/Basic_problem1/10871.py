list_len, threshold = map(int, input().split())
maps = map(int, input().split())
for i in range(list_len):
    num = maps.__next__()
    if threshold>num:
        print(num, end=' ')