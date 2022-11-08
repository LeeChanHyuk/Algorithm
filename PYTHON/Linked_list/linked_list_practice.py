class node():
    def __init__(self, data) -> None:
        self.data = data
        self.prev = None
        self.next = None

class linkedList():
    def __init__(self, data) -> None:
        self.head = node(data)
        self.tail = self.head
        self.length = 1

    def add_node(self, data):
        if self.length != 0:
            new_node = node(data)
            self.head.prev = new_node
            self.tail.next = new_node
            new_node.prev = self.tail
            new_node.next = self.head
            self.tail = new_node
            self.length += 1
        else:
            self.head = node(data)
            self.tail = self.head

    def delete_node_by_index(self, index):
        pivot = 0
        current_node = self.head
        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            while pivot < index:
                current_node = current_node.next
                pivot += 1
            current_node.prev.next = current_node.next
            current_node.next.prev = current_node.prev
    
    def put_node_by_index(self, index, data):
        pivot = 0
        current_node = self.head
        if self.length == 0:
            if index == 0:
                self.head = node(data)
                self.tail = self.head
                self.length += 1
            else:
                print('Please enter correct index number')
        else:
            while pivot < index:
                current_node = current_node.next
                pivot += 1
            new_node = node(data)
            current_node.prev.next = new_node
            new_node.prev = current_node.prev
            new_node.next = current_node
            self.length += 1

    def print_the_data_by_index(self, index):
        pivot = 0
        current_node = self.head
        while pivot < index:
            current_node = current_node.next
            pivot += 1
        print(current_node.data)

linked_list = linkedList(0)
for i in range(1, 10):
    linked_list.add_node(i)

for i in range(10):
    linked_list.print_the_data_by_index(i)

linked_list.put_node_by_index(2, 10)
        
for i in range(11):
    linked_list.print_the_data_by_index(i)