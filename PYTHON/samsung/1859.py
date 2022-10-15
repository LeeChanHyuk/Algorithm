from sys import stdin

test_case = int(stdin.readline().strip())
for case in range(test_case):
	N = int(stdin.readline().strip())
	prices = list(map(int, stdin.readline().strip().split(' ')))
	D = [0] * len(prices)

	max_num = 0
	for i in range(len(prices)-1, -1, -1):
		if max_num >= prices[i]:
			D[i] = max_num - prices[i]
		else:
			max_num = prices[i]
	print('#'+str(case+1)+' ', end='')
	print(sum(D))