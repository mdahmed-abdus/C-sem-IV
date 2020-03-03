# to implement multilevel inheritance
class Pet:
    def __init__(self, animal):
        self.animal = animal

    def show_animal(self):
        print("Animal:", self.animal)


class Dog(Pet):
    def __init__(self, animal, name):
        super().__init__(animal)
        self.name = name

    def show_name(self):
        print("Name:", self.animal)

    def bark(self):
        print(self.name, "is barking")


class Puppy(Dog):
    def eat(self):
        print(f"Puppy {self.name} is eating")


puppy = Puppy("Dog", "Barky")
puppy.show_animal()
puppy.show_name()
puppy.bark()
puppy.eat()
