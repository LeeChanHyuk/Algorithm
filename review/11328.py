from sys import stdin
N = int(stdin.readline().strip())
success = True
for i in range(N):
    alphabet = [0] * 26
    a, b = stdin.readline().strip().split(' ')
    for char in a:
        alphabet[ord(char)-97] += 1
    for char in b:
        alphabet[ord(char)-97] -= 1
    for i in range(26):
        if alphabet[i] != 0:
            success=False
            break
    if success:
        print('Possible')
    else:
        print('Impossible')
        success = True