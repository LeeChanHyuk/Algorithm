from sys import stdin

N, K = map(int, stdin.readline().strip().split(' '))
cs = []
for i in range(N):
	input = int(stdin.readline().strip())
	if input <= K:
		cs.append(input)
last = K
nums = 0
for i in range(len(cs)-1, -1, -1):
	if cs[i] <= last:
		last_in_cs = int(last // cs[i])
		last = last - (cs[i] * last_in_cs)
		nums += last_in_cs
	if last == 0:
		break
print(nums)