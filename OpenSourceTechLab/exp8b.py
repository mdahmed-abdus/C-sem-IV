from data_structures.queue import Queue

size = int(input("Enter the size of the queue: "))
queue = Queue(size)

while True:
    choice = int(input("Enter your choice [0 - show menu]: "))

    if choice == 0:
        print("1. Insert element")
        print("2. Delete element")
        print("3. Display all elements")
        print("Any other number to exit")
    elif choice == 1:
        element = input("Enter the element to insert: ")
        queue.insert(element)
    elif choice == 2:
        element = queue.delete()
        if element is not None:
            print("Element deleted is:", element)
    elif choice == 3:
        queue.display()
    else:
        print("Exited")
        break
