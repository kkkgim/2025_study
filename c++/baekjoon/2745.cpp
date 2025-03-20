#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    int n,len = str.length();
    std::cin >> n;

    int sum =0;
    int square = 1;
    
    for(int i=0; i<len; i++){
        char x = str[len-1-i];
        if('A' <= x && x <= 'Z'){
            sum += ((int)(x-55)) * square;
        }
        else sum += (x-'0') * square;
        square *= n;
    }
    std::cout << sum << std::endl;
    return 0;
} 