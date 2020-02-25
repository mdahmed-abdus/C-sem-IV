# using while loop to find power of a number

num = int(input("Enter the number: "))
power = int(input("Enter the power: "))

ans, i = 1, 1
while i <= power:
    ans *= num
    i += 1

print(f"{num} to the power {power} = {ans}")
