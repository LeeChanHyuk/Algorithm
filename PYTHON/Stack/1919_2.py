import os
import sys

word1 = sys.stdin.readline().strip()
word2 = sys.stdin.readline().strip()

alphabet = [0] * 26

for i in range(len(word1)):
    alphabet[ord(word1[i])-97] += 1

for j in range(len(word2)):
    alphabet[ord(word2[j])-97] -= 1

sum = 0
for k in range(26):
    sum += abs(alphabet[k])

print(sum)