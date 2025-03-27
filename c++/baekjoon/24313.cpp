#include <iostream>
#include <string>

int main() {
    int x,y,c,n;
    std::cin >> x >> y;
    std::cin >> c;
    std::cin >> n;

    if (x * n + y <= c * n && x <= c) std::cout << 1 << std::endl;
    else std::cout << 0 << std::endl;

    return 0;
} 