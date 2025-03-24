#include <iostream>
#include <string>

int main() {
    int x,div=2;
    std::cin >> x;

    if(x==1)  std::cout << 1 << std::endl;
    while(x>1){
        if(x%div == 0){
            std::cout << div << std::endl;
            x = x/div;
        }
        else div++;
    }
    return 0;
} 