#include <iostream>
#include <string>

int main() {

    int x,y,z;
    std::cin >> x >> y >> z;

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
    
    if(x >= y+z ) std::cout << (y+z)*2 -1 << std::endl;
    else std::cout << x+y+z << std::endl;

    return 0;
} 