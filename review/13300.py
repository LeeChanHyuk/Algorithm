from sys import stdin
N, K = map(int, stdin.readline().strip().split(' '))
students = dict()
for i in range(N):
	student = input()
	if students.get(student):
		students[student] += 1
	else:
		students[student] = 1
students = list(students.values())
sum = 0
for i in range(len(students)):
	sum += int(students[i]/K)
	if students[i]%K != 0:
		sum += 1
print(sum)