#include <iostream>
#include <string>

int main() {
    int n, change;
    std::cin >> n;
    int arr[] ={25,10,5,1};

    for(int i=0; i<n; i++){
        std::cin >> change;
        // 쿼터(Quarter, $0.25)의 개수, 다임(Dime, $0.10)의 개수, 니켈(Nickel, $0.05)의 개수, 페니(Penny, $0.01)
        // 거스름돈은 항상 $5.00 이하이고, 손님이 받는 동전의 개수를 최소
        for(int j=0; j<4; j++){
            std::cout << (change/arr[j]) << ' ';
            change = change%arr[j];
        }
        std::cout << std::endl;
    }
    return 0;
} 

