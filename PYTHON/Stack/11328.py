from sys import stdin
command_num = int(stdin.readline().strip())
char_list = [0] * 26
for i in range(command_num):
    word_1, word_2 = stdin.readline().strip().split()
    if len(word_1) != len(word_2):
        print('Impossible')
        continue
    for j in range(len(word_1)):
        char_list[ord(word_1[j]) - 97] += 1
        char_list[ord(word_2[j]) - 97] -= 1
    impossible = False
    for j in range(26):
        if char_list[j] != 0 and impossible is False:
            print('Impossible')
            impossible = True
        if j == 25 and impossible is False:
            print('Possible')
        char_list[j] = 0


