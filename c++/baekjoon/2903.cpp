#include <iostream>
#include <string>


int main() {
    int n;
    std::cin >> n;

    int sum = 0;
    int cnt = 0;

    while(true){
        sum += cnt;
        if(n<=sum){
            if(cnt%2 == 0) std::cout << (cnt-(sum-n)) << '/' << (1+(sum-n)) << std::endl;
            else std::cout << (1+(sum-n)) << '/'  << (cnt-(sum-n)) << std::endl;
            break;
        }
        cnt++;
    }

    return 0;
} 

