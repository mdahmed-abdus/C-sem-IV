# explore basics data types of python

import array

# string
print("\nString")

usr_str = input("Enter a string: ")

usr_str_length = len(usr_str)
usr_str_swapcase = usr_str.swapcase()
usr_str_uppercase = usr_str.upper()

print("Length of entered string is:", usr_str_length)
print("Swappedcase string:", usr_str_swapcase)
print("Uppercase string:", usr_str_uppercase)

# list
print("\nList")

fruits = ["apple", "mango", "watermelon", "guava", "muskmelon"]
numbers = [1, 2, 3, 4, 5, 5, 5]

fruits_length = len(fruits)
fruits.append(5)
numbers_count_5 = numbers.count(5)
numbers_sum = sum(numbers)

print(fruits)
print("Length of list fruits:", fruits_length)
print(numbers)
print("Count of 5 in list number:", numbers_count_5)
print("Sum of elements of numbers:", numbers_sum)

# array
print("\nArray")

# import array -> to use array
float_array = array.array('d', [1.1, 3.5, 4.5])
int_array = array.array('i', [2, 4, 6, 8, 5, 9, 1])

float_array.append(5.9)
int_array.remove(8)
int_array.pop()

print(float_array)
print(int_array)

# dictionary
print("\nDictionary")

dict = {
    "0": "zero",
    "1": "one",
    "2": "two"
}

number = input("Enter the number: ")

dict["3"] = "three"
word = dict[number]

print(dict)
print(number, "in words = ", word)

# set
print("\nSet")

cities = {"Mumbai", "New Delhi", "Hyderabad", "Banglore"}

cities.add("London")
cities.update(["Tokyo", "Moscow", "Mexico", "Apple"])
cities.discard("Apple")

print(cities)

# tuples
print("\nTuples")

numbers_list = [1, 2, 3, 4, 5, 6]
alphas_list_tuple = ('a', 'b', 'c')

numbers_list_tuple = tuple(numbers_list)
sum_tuple = numbers_list_tuple + alphas_list_tuple

print(numbers_list_tuple)
print(numbers_list_tuple[2:4])
print(sum_tuple)
