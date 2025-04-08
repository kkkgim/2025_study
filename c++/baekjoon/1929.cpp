#include <iostream>
#include <set>
#include <cmath>

using namespace std;

bool is_prime(long long  num){
    if(num < 2) return false;
    for(long i=2; i <= sqrt(num); i++){
        if(num%i==0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a,b;
    cin >> a >> b;
    
    for(long long i = a; i<= b; i++){
        if(is_prime(i)) cout << i << '\n';
    }
    
    return 0;
}