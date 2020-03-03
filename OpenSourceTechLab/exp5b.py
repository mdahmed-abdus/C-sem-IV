# demonstrate exceptional handling

dividend = int(input("Enter the dividend: "))
divisor = int(input("Enter the divisor: "))

try:
    quotient = dividend / divisor
    print(f"{dividend} / {divisor} = {quotient}")
except(ZeroDivisionError):
    print(f"{dividend} / {divisor} = Infinity")
finally:
    print("Division completed")
