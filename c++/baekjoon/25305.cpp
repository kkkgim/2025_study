#include <iostream>
#include <string>

int main() {
    int n, cut ;
    std::cin >> n >> cut;

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

    std::cout <<  arr[n-cut] <<std::endl;

    return 0;
}