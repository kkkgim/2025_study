#include <iostream>

using namespace std;

int gcd(int x , int y){
    while(y){
        int tmp = x%y;
        x=y;
        y=tmp;
    }
    return x;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int x = a*d + b*c;
    int y = b * d;

    int G = gcd(x,y);
    cout << x/G << ' ' << y/G ;
    
    return 0;
}