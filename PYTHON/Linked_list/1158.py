from mimetypes import init
from sys import stdin
numbers, num = map(int, stdin.readline().strip().split(' '))
class node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None
        self.prev = None

class linked_list:
    def __init__(self, data) -> None:
        self.zero = node(0)
        self.head = node(data)
        self.zero.next = self.head
        self.zero.prev = node(-1)
        self.head.next = self.head
        self.head.prev = self.head

    def append(self, data):
        curr = self.head.prev
        curr.next = node(data)
        curr.next.prev = curr
        curr.next.next = self.head
        self.head.prev = curr.next
    
    def pop(self, index):
        curr = self.head
        for i in range(index):
            curr = curr.next
        curr.prev.next = curr.next
        curr.next.prev = curr.prev

linked_list_1 = linked_list(1)
# data append from input numbers
for i in range(2, numbers + 1):
    linked_list_1.append(i)

curr = linked_list_1.zero
print('<', end='')
while 1:
    for i in range(num):
        curr = curr.next
    print(curr.data, end='')
    curr.prev.next = curr.next
    curr.next.prev = curr.prev
    if curr.data == curr.prev.data:
        print('>')
        break
    else:
        print(', ', end='')



        