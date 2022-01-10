from sys import stdin
words = stdin.readline().strip()
alphabet = [0] * 26
for word in words:
    alphabet[ord(word) - 97] += 1
for i in alphabet:
    print(i, sep=' ')

word = input()
for i in range(26):
    print(word.count(chr(i+97)))