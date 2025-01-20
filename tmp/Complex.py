class Complex:
    r = 5.0
    i = 5.0
 
    def print(self):
        print(f'Complex : {self.r} + {self.i}i')
 
    def change(self, r, i):
        self.r = r
        self.i = i

c1 = Complex()
c2 = Complex()
 
c1.print()
c2.print()

# c1 객체는 같은 이름의 클래스 변수, 객체 변수가 있기 때문에 
# print 메소드에서는 이제 객체 변수에 우선적으로 접근
c1.r = 10.0
c1.i = 7.0
 
c1.print()
c2.print()