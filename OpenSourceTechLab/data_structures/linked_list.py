class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        node = Node(data)

        if self.head is None:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node

    def delete(self, data):
        node = self.head

        if self.head is None:
            print("List underflow")
            return
			
        if self.head.data == data:
            self.head = self.head.next
            node = None
            print("Deleted:", data)
            return

        while node.data != data:
            prev = node
            node = node.next

            if node is None:
                print("Invalid location")
                return None

        prev.next = node.next
        node = None
        print("Deleted:", data)

    def display(self):
        node = self.head

        if node is None:
            print("List is empty")
        else:
            print("List elements are:")
            while node is not None:
                print(node.data, end=" ")
                node = node.next
            print()
