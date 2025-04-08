#include <iostream>

using namespace std;

// 최대공약수(GCD) 구하기
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int n, a, b;
    cin >> n;

    while (n--) {
        // LCM = G*m*n // m,n 은 서로소
        // A = a*G
        // B = b*G 
        cin >> a >> b;
        cout << (a * b) / gcd(a, b) << '\n';
    }
    
    return 0;
}