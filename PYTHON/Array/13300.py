from sys import stdin
N, k = map(int, stdin.readline().strip().split(' '))
student = [0]*13
for i in range(N):
    sex, classes = map(int, stdin.readline().strip().split(' '))
    student[(sex*6)+classes] += 1
room = 0
for i in range(len(student)):
    room += int(student[i]/k)
    if (student[i] % k) != 0:
        room += 1
print(int(room))

