#include <iostream>
#include <string>

int main() {
    int x,y;
    std::cin >> x >> y;

    int min = 0;
    int sum = 0; 

    for(int i=x;i<y+1;i++){       
        // 소수판단
        bool chk = true;
        for(int j=2; j<i; j++){
            if(i%j == 0){
                chk = false;
                break;
            }
        }

        if((chk && i!=1) || i==2){
            if(min==0) min = i;
            sum += i;
        }        
    }
    if(sum == 0 ) std::cout << -1 <<std::endl;
    else std::cout << sum << '\n' << min <<std::endl;
    return 0;
} 