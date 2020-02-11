# using for loop to find prime number in range

limit = int(input("Enter the upper limit: "))

print("Prime numbers are:")
for num in range(1, limit + 1):
    for div in range(2, num):
        if num % div == 0:
            break
    else:
        print(num, end=" ")
print()
