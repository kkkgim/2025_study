class Dog:
    # mistaken use of a class variable
    tricks = []             
 
    def __init__(self, name):
        self.name = name
 
    def instance_trick(self, trick):
        self.tricks = [trick]

    def add_trick(self, trick):
        self.tricks.append(trick)
 
d1 = Dog('Fido')
d2 = Dog('Buddy')
d1.add_trick('roll over')
d2.add_trick('play dead')
print(d1.tricks)
print(d2.tricks)

# 클래스 변수와 객체 변수가 같은 이름이라면, 객체 변수가 우선적으로 참조
d1.instance_trick('roll over2')
print(d1.tricks)
print(d2.tricks)
