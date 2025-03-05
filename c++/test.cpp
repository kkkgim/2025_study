#include <iostream>

class A{
    int x=10;
    public:
        int get_x() const {return x;}
        int& access_A() {return x;}
};


int main() {
    A a = A();
    int& num = a.access_A();
   
    std::cout << "num : " << num << ", a : " << a.access_A() << std::endl;
    num = 3;
    std::cout << "num : " << num << ", a : " << a.access_A() << std::endl;
}

