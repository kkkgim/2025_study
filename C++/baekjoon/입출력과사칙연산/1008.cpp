#include <iostream>

int main(){
    // float 32비트 부동소수점 형식 => 정밀도는 약 7자리, 9자리까지 출력하면 부정확함
    // double 64비트 부동소수점 형식 => 정밀도는 약 15자리까지 출력 가능
    double a,b;
    
    std::cin >> a >> b ;
    std::cout.precision(9);
    std::cout << std::fixed;
    std::cout << (a/b) << std::endl;

}