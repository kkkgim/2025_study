#include <iostream>
#include <string>

int main() {
    int arr[100][100] = {0};
    int n,x,y,sum = 0;
    std::cin >> n;

    for(int i=0; i<n; i++){
        std::cin >> x >> y;
        for(int i=x; i<x+10; i++){

            for(int j=y; j<y+10; j++){
                arr[i-1][j-1] = 1;
            }
        }
    }
    
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            sum += arr[i][j];
        }
    }
    std::cout << sum << std::endl;

    return 0;
} 