#include <iostream>
#include <string>

int main() {
    int x,y,w,h;
    std::cin >> x >> y >> w >> h;

    int min = x;

    if(w-x < min) min = w-x;
    if(y < min) min = y;
    if(h-y < min) min = h-y;

    std::cout << min  <<std::endl;
    
    return 0;
} 