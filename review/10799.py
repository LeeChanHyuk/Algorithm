from sys import stdin # 즉, 지금까지의 막대기 수, 현재 오픈된 막대기 수, 마지막 입력. 3개만 있으면 될 듯.
line = stdin.readline().strip()
stack = []
previous_stick = 0
current_stick = 0
last_input = 'a'
for char in line:
    if char == '(':
        current_stick += 1
    else: # char == ')'
        if last_input == '(':
            current_stick -= 1
            previous_stick += current_stick
        else: # last_input == ')'
            current_stick -= 1
            previous_stick += 1
    last_input = char
print(previous_stick)