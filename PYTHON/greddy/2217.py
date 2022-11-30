from sys import stdin
from collections import deque

N = int(stdin.readline().strip())
lopes = []
lopes_deque = dict()
for i in range(N):
	num = int(stdin.readline().strip())
	if num not in lopes_deque.keys():
		lopes_deque[num] = 1
		lopes.append(num)
	else:
		lopes_deque[num] += 1
lopes.sort(key = lambda x: x)
lopes.reverse()
total_num = 0
min_weight = 10002
droped_min_num = 0
for i in range(len(lopes)):
	if total_num * min_weight > (total_num + lopes_deque[lopes[i]] + droped_min_num) * lopes[i]:
		droped_min_num += lopes_deque[lopes[i]]
		continue
	else:
		total_num += (droped_min_num + lopes_deque[lopes[i]])
		droped_min_num = 0
		min_weight = lopes[i]
print(total_num * min_weight)
	

