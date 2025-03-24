#include <iostream>
#include <string>

int main() {
    int n,x;
    
    std::cin >> n;
    int cnt = n;
    
    for(int i=0;i<n;i++){
        std::cin >> x ;
        if(x==1) cnt--;
        for(int j=2;j<x;j++){
            if(x%j==0) {
                cnt--;
                break;
            }
        }
    }

    std::cout << cnt <<std::endl;
    return 0;
} 