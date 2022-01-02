from sys import stdin

test_result = int(stdin.readline())
if test_result>=90:
    print('A')
elif test_result>=80:
    print('B')
elif test_result>=70:
    print('C')
elif test_result>=60:
    print('D')
else:
    print('F')