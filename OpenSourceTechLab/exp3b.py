# lambda function to find power of a number
power = lambda number, raise_to: number ** raise_to

number = int(input("Enter the number to find its power: "))
raise_to = int(input("Enter the power: "))

ans = power(number, raise_to)
print(f"{number} raise to {raise_to} = {ans}")
