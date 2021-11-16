import sys
import os

queue = list()

input_num = map(int,sys.stdin.readline)
for i in range(1,input_num+1):
    queue.append(i)

front = 0
while(len(queue)>1):
    front += 1
    queue.append(queue[front])
    front += 1

print(queue[front])