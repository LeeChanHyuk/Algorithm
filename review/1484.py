from sys import stdin
import math
G = int(stdin.readline().strip())
success = -1
for i in range(1, 50010): # i is previous weight
	sqrt_result = math.sqrt((i*i)+G)
	if sqrt_result - int(sqrt_result) < 0.00000001:
		print(int(sqrt_result))
		success += 1
if success == -1:
	print(-1)