from sys import stdin

N, K = map(int, stdin.readline().strip().split(' '))

weights = []
values = []

for i in range(N):
	weight, value = map(int, stdin.readline().strip().split(' '))
	weights.append(weight)
	values.append(value)

min_weight = min(weights)
D = [0] * (K+1)
# D[i]는 i (weight)만큼의 물건을 넣었을 때, 가장 큰 value 값.
# D[i] = max(D[i], D[i-weights[j]])
last_j = -1
for i in range(min_weight, K+1):
	for j in range(N):
		if i-weights[j] < 0:
			continue
		if D[i] < D[i-weights[j]] + values[j]:
			D[i] = D[i-weights[j]] + values[j]
			last_j = j
	weights[last_j] = 100002
print(max(D))

