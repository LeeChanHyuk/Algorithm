from sys import stdin
class node:
	def __init__(self, data) -> None:
		self.data = data
		self.next = None
		self.prev = None

class linked_list:
	def __init__(self) -> None:
		self.head = None
		self.tail = None
		self.curr = None
	
	def append(self, data) -> None:
		if self.head is None:
			self.head = node(data)
			self.head.next = self.head
			self.head.prev = self.head
			self.curr = self.head
		else:
			self.head.prev.next = node(data)
			self.head.prev.next.prev = self.head.prev
			self.head.prev = self.head.prev.next
			self.head.prev.next = self.head

			
	def pop(self, index):
		curr = self.curr
		for i in range(index-1):
			curr = curr.next
		if curr == self.curr:
			self.curr = self.curr.next
		curr.next.prev = curr.prev
		curr.prev.next = curr.next
		return curr.data
	
	def move(self, index):
		for i in range(index):
			self.curr = self.curr.next
	

N, K = map(int, stdin.readline().strip().split(' '))
linked_list_1 = linked_list()
for i in range(N):
	linked_list_1.append(i+1)
deleted_num = 0
print('<', end='')
for i in range(N):
	linked_list_1.move(K-1)
	if i == N-1:
		print(linked_list_1.pop(0), end='')
	else:
		print(linked_list_1.pop(0), end=', ')
print('>')