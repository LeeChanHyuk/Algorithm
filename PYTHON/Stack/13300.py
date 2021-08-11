from sys import stdin
student_num, max_per_room = map(int,stdin.readline().strip().split())
students = [0] * 12
for i in range(student_num):
    sex, classes = map(int,stdin.readline().strip().split())
    students[(sex*6) + (classes-1)] += 1
room_count = 0
for i in range(12):
    room_count += int(students[i] / max_per_room)
    if students[i] % max_per_room > 0:
        room_count += 1
print(room_count)
