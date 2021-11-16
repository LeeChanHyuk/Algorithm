import os
import sys

input_num, threshold = map(int,sys.stdin.readline().strip().split())
inputs = map(int, sys.stdin.readline().split())
for i in range(input_num):
    num = inputs.__next__()
    if num < threshold:
        print(num, end=' ')
