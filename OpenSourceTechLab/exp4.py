# demonstrate classes, objects and single inheritance
class Person:
    def __init__(self, first_name, last_name):
        self.first_name = first_name
        self.last_name = last_name
        self.full_name = first_name + " " + last_name

    def greet(self):
        print("Hello", self.full_name, "have a nice day!")


class Student(Person):
    def __init__(self, first_name, last_name, roll_no, branch):
        super().__init__(first_name, last_name)
        self.roll_no = roll_no
        self.branch = branch

    def show_details(self):
        print("Roll no:", self.roll_no)
        print("Full name:", self.full_name)
        print("Branch:", self.branch)


first_name = input("Enter the first name of the student: ")
last_name = input("Enter the last name of the student: ")
roll_no = input("Enter the roll number of the student: ")
branch = input("Enter the branch of the student: ")

student = Student(first_name, last_name, roll_no, branch)
student.greet()
student.show_details()
