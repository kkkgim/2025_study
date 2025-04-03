#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        std::cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for(int i=0; i<n; i++){
        std::cout << arr[i]<<std::endl;
    }
    
    return 0;
}