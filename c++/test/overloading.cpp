#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl;}
void print(double x) { std::cout << "double : " << x << std::endl;}

int main(){
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);
    
}