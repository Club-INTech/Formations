class Animal:
    def __init__(self, home: str) -> None:
        print("Ceci est un animal")
        self.home = home
    
    def voice(self) -> None:
        pass

class Dog(Animal):
    def __init__(self) -> None:
        super().__init__("local")
        print("Ceci est un dog")
    
    def voice(self) -> None:
        print("ouf")

class Cat(Animal):
    def __init__(self) -> None:
        super().__init__("rue")
        print("Ceci est un cat")
    
    def voice(self) -> None:
        print("meow")

dog = Dog()
cat = Cat()
dog.voice()
cat.voice()
