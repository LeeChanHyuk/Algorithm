from sys import stdin

def common_biggest_num(A, B):
	if A == 0:
		return B
	return common_biggest_num(B%A, A)
	
def least_common_num(A, B):
	return int(A / common_biggest_num(A, B) * B)

a, b, L = map(int, stdin.readline().strip().split(' '))
	
first_least_num = least_common_num(a, b)
last = L / first_least_num
if last - int(last) > 0.001:
	print(-1)
else:
	result = -1
	last = int(last)
	for i in range(last, L+1, last):
		if least_common_num(first_least_num, i) == L:
			result = i
			break
	print(result)

