from sys import stdin
word_1 = stdin.readline().strip()
word_2 = stdin.readline().strip()
alphabet = [0] * 26
delete_final_num = 0
for i in range(len(word_1)):
    alphabet[ord(word_1[i])-97] += 1
for i in range(len(word_2)):
    alphabet[ord(word_2[i])-97] -= 1
for i in range(len(alphabet)):
    if alphabet[i] != 0:
        delete_final_num += abs(alphabet[i])
print(delete_final_num)