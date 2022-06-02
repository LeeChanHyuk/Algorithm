from sys import stdin
alphabets = [0] * 26
words = input()
for word in words:
	alphabets[ord(word)-97] += 1
words = input()
for word in words:
	alphabets[ord(word)-97] -= 1
add_nums = 0
for i in alphabets:
	if i != 0:
		add_nums += abs(i)
print(add_nums)