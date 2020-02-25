class Queue:
    def __init__(self, size):
        self.queue = []
        self.size = size

    def insert(self, element):
        if len(self.queue) < self.size:
            self.queue.append(element)
        else:
            print("Queue overflow")

    def delete(self):
        try:
            return self.queue.pop(0)
        except:
            print("Queue underflow")
            return None

    def display(self):
        if len(self.queue) == 0:
            print("Queue empty")
        else:
            print("Queue elements are:")
            for element in self.queue:
                print(element, end=" ")
            print()
