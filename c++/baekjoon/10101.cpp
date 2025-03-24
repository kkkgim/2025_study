#include <iostream>
#include <string>

int main() {
    int arr[3];
    for(int i=0; i<3; i++){
        std::cin >> arr[i];
    }

    if(arr[0]+arr[1]+arr[2] != 180) std::cout << "Error" << std::endl;
    else if(arr[0]==arr[1] && arr[1] == arr[2]) std::cout << "Equilateral" << std::endl;
    else if(arr[0]==arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) std::cout << "Isosceles" << std::endl;
    else std::cout << "Scalene" << std::endl;
    
    return 0;
} 