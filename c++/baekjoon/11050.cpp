#include <iostream>

using namespace std;

int fact(int num) {
    if (num <= 1) return 1;
    return num * fact(num - 1);
}


int main(){
    int n,k;
    cin >> n >> k;

    cout << fact(n) / (fact(k) * fact(n-k)) ;
    return 0;
}