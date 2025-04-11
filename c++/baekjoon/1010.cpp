#include <iostream>

using namespace std;

long long comb(int m, int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        // m!/(m-n)! 계산
        res *= (m - i + 1); 
        // n! 계산
        res /= i;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    long long n,m;
    while(T--){
        cin >> n >> m;
        cout << comb(m,n) << '\n';
    }
}