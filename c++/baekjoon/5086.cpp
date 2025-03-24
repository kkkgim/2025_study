#include <iostream>
#include <string>

int main() {
    int x,y;
    while (true){
        std::cin >> x >> y;

        if(x==0 && y==0) break;
        if(y%x==0)  std::cout << "factor" << std::endl;
        else if(x%y==0)  std::cout << "multiple" << std::endl;
        else std::cout << "neither" << std::endl;
    }
    return 0;
} 