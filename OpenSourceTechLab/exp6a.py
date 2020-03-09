# working with files and directories
# append data to existing file and display it

file_name = input("Enter the file name: ")

with open(file_name, "a") as target:
    data = input("Enter the data to append: ")
    target.write(data + "\n")
    print("Data appended")

with open(file_name, "r") as source:
    print("File data is:")
    print(source.read())
