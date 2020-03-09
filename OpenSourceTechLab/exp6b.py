# working with files and directories
# count number of lines, words and characters in a file

count_line = 0
count_words = 0
count_chars = 0

file_name = input("Enter the file name: ")

try:
    with open(file_name, 'r') as source:
        for line in source:
            words = line.split()

            count_line += 1
            count_words += len(words)
            count_chars += len(line)

    print("Number of lines:", count_line)
    print("Number of words:", count_words)
    print("Number of characters:", count_chars)
except(FileNotFoundError):
    print("File not found")
