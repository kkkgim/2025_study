#include <iostream>
#include <vector>

int main() {
    int x;
    
    while(true){
        std::cin >> x;
        if(x==-1) break;

        int sum = 0;
        std::vector<int> v; 

        for(int i=1;i<x;i++){
            if(x%i==0) {
                    sum+=i;
                    v.push_back(i);
            }
        }
        if(x==sum){
            std::cout << x << " = " ;
            for(int i=0;i<v.size();i++){
                std::cout << v[i] ;
                if(i<v.size()-1) std::cout << " + ";
            }
            std::cout << std::endl;
        }
        else std::cout << x << " is NOT perfect." << std::endl;
        
    } 
    return 0;
} 