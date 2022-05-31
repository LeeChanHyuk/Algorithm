from sys import stdin
N = int(stdin.readline().strip())
lists = [i for i in range(N)]
front = 0
while 1:
	if front + 1 == len(lists):
		break
	front += 1
	lists.append(lists[front])
	front += 1
print(lists[front]+1)