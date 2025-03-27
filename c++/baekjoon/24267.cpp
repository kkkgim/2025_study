#include <iostream>
#include <string>

int main() {
    long long n;
    std::cin >> n;

    long long result = (n * (n-1) * (n-2)) / 6 ;
    std::cout << result << '\n' << 3 <<std::endl;

    return 0;
} 