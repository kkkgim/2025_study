#include <iostream>
#include <string>

void formation(long long n, long long div){
    if(n/div >= div){
        formation(n/div, div);
        char x = '0'+(n%div);
        if('9' < x) x = ('A' + (n % div - 10)) ;

        std::cout << x;
    }
    else {
        char x = '0'+(n/div);
        char y = '0'+(n%div);
        if('9'< x){
            x = ('A' + (n / div - 10)) ;
        }

        if('9'< y){
            y = ('A' + (n % div - 10)) ;
        }
        if ('0'==x){
            std::cout << y;
        } 
        std::cout << x << y;
    }

}
int main() {
    long long n,div ;
    std::cin >> n >> div;

    formation(n, div);    
    return 0;
} 