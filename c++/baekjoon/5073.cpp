#include <iostream>
#include <string>

int main() {

    while(true){
        int x,y,z;
        std::cin >> x >> y >> z;

        if(x==0 || y==0 || z == 0 ) break;

        if(y>x) {
            int tmp = y;
            y=x;
            x=tmp;
        }
        if(z>x) {
            int tmp = z;
            z=x;
            x=tmp;
        }
        
        if(x >= y+z ) std::cout << "Invalid" << std::endl;
        else if(x==y && y==z) std::cout << "Equilateral" << std::endl;
        else if(x==y || y==z || x==z) std::cout << "Isosceles" << std::endl;
        else std::cout << "Scalene" << std::endl;
    }
    return 0;
} 