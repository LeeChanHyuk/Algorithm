from sys import stdin

n, x = map(int, stdin.readline().strip().split(' '))
arr = map(int, stdin.readline().strip().split(' '))
for i in arr:
    if i<x:
        print(i)