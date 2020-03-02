from data_structures.linked_list import LinkedList

linked_list = LinkedList()

while True:
    choice = int(input("Enter your choice [0 - show menu]: "))

    if choice == 0:
        print("1. Insert element")
        print("2. Delete element")
        print("3. Display all elements")
        print("Any other number to exit")
    elif choice == 1:
        element = input("Enter the element to be inserted: ")
        linked_list.insert(element)
    elif choice == 2:
        element = input("Enter the element to be deleted: ")
        linked_list.delete(element)
    elif choice == 3:
        linked_list.display()
    else:
        print("Exited")
        break
