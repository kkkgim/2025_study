#include <iostream>
#include <string>

int main() {
    int x,y;
    int cnt = 0;
    int result = 0;
    
    std::cin >> x >> y;
    
    for(int i=1;i<x+1;i++){
        if(x%i==0) cnt++;
        if(cnt==y) {
            result = i ;
            break;
        }
    }

    std::cout << result <<std::endl;
    return 0;
} 