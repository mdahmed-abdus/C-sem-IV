# function to find factorial of a number
def factorial(number):
    if number < 0:
        return 0
    elif number == 0:
        return 1
    return factorial(number - 1) * number


number = int(input("Enter the number to find it's factorial: "))
ans = factorial(number)
print(f"The factorial of {number} = {ans}")
