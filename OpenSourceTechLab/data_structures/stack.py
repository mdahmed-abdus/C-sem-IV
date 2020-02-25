class Stack:
    def __init__(self, size):
        self.stack = []
        self.size = size

    def push(self, element):
        if len(self.stack) < self.size:
            self.stack.append(element)
        else:
            print("Stack overflow")

    def pop(self):
        try:
            return self.stack.pop()
        except:
            print("Stack underflow")
            return None

    def peek(self):
        try:
            return self.stack[-1]
        except:
            print("Stack empty")
            return None

    def display(self):
        if len(self.stack) == 0:
            print("Stack empty")
        else:
            print("Stack elements are:")
            for element in self.stack:
                print(element, end=" ")
            print()
