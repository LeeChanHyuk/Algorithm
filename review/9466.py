from sys import stdin

def dfs(temp_team, via, students):
    while 1:
        current_student = temp_team[-1]
        if via[current_student] > 0:
            temp_team.pop()
            if current_student in temp_team:
                team_min_index = temp_team.index(current_student)
                return temp_team[team_min_index:]
            else:
                return []
        via[current_student] = 1
        temp_team.append(students[current_student])

t = int(stdin.readline())
for _ in range(t):
    student_num = int(stdin.readline())
    via = [0] * (student_num + 1)
    students = [0] + list(map(int, stdin.readline().split(' ')))
    team = [] # all students which is in correct team
    for i in range(1, len(students)):
        if via[i] > 0:
            continue
        else:
            temp_team = []
            temp_team.append(i)
            temp_team = dfs(temp_team, via, students)
            team += temp_team
    print(student_num - len(team))
    