#include <iostream>
#include <string>

int main() {

    int arr[5];
    int avg = 0;
    for(int i=0; i<5; i++){
        std::cin >> arr[i];
        avg+=arr[i];
    }


    for(int i=0; i<5; i++){
        for(int j=i;j<5;j++){
            if(arr[i]>arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    std::cout << (avg/5) << '\n' << arr[2] <<std::endl;

    return 0;
}