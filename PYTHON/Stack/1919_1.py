from sys import stdin
input = stdin.readline().strip()
target = stdin.readline().strip()
alphabet = [0] * 26
for i in range(len(input)):
    alphabet[ord(input[i])-97] += 1
for i in range(len(target)):
    alphabet[ord(target[i]) - 97] -= 1
count = 0
for i in range(26):
    count += abs(alphabet[i])
print(count)