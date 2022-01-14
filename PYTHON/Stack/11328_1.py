from sys import stdin

N = int(stdin.readline().strip())
for i in range(N):
    alphabet = [0] * 26
    target, input = stdin.readline().strip().split(' ')
    for i in target:
        alphabet[ord(i) - 97] += 1
    for i in input:
        alphabet[ord(i) - 97] -= 1
    possible = True
    for i in alphabet:
        if i != 0: 
            possible = False
    if possible:
        print('Possible')
    else:
        print('Impossible')
