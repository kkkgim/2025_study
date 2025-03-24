#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int min_x = 10000;
    int min_y = 10000;
    int max_x = -10000;
    int max_y = -10000;

    for(int i=0; i<n; i++){
        int x, y;
        std::cin >> x >> y;

        if(min_x > x) min_x=x;
        if(max_x < x) max_x=x;

        if(min_y > y) min_y=y;
        if(max_y < y) max_y=y;

    }
    
    std::cout << (max_x - min_x) * (max_y - min_y)  <<std::endl;
    return 0;
} 