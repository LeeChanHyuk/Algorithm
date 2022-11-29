from sys import stdin

N = int(stdin.readline().strip())
time_tables = []
for i in range(N):
	time_tables.append(list(map(int, stdin.readline().strip().split(' '))))
time_tables.sort(key=lambda x:(x[1], x[0]))
end_time = 0
conferences = 0
for i in range(N):
	if end_time > time_tables[i][0]:
		continue
	conferences += 1
	end_time = time_tables[i][1]
print(conferences)

