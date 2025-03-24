#include <iostream>
#include <string>

int main() {
    int arr_x[3];
    int arr_y[3];
    for(int i= 0;i<3;i++){
        int x,y;
        std::cin >> arr_x[i] >> arr_y[i];
    }

    int x, y;
    if(arr_x[0]==arr_x[1]) x = arr_x[2];
    else if(arr_x[0]==arr_x[2]) x = arr_x[1];
    else x = arr_x[0];

    if(arr_y[0]==arr_y[1]) y = arr_y[2];
    else if(arr_y[0]==arr_y[2]) y = arr_y[1];
    else y = arr_y[0];

    std::cout << x << ' ' << y  <<std::endl;
    
    return 0;
} 