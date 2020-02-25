from data_structures.stack import Stack

size = int(input("Enter the size of the stack: "))
stack = Stack(size)

while True:
    choice = int(input("Enter your choice [0 - show menu]: "))

    if choice == 0:
        print("1. Push element")
        print("2. Pop element")
        print("3. Peek element")
        print("4. Display all elements")
        print("Any other number to exit")
    elif choice == 1:
        element = input("Enter the element to push: ")
        stack.push(element)
    elif choice == 2:
        element = stack.pop()
        if element is not None:
            print("Element popped is:", element)
    elif choice == 3:
        element = stack.peek()
        if element is not None:
            print("Top element is:", element)
    elif choice == 4:
        stack.display()
    else:
        print("Exited")
        break
