#include <iostream>
#include <set>
#include <cmath>

using namespace std;

bool is_prime(int num){
    if(num < 2) return false;
    for(int i=2; i <= sqrt(num); i++){
        if(num%i==0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n=1;
    while(n){
        cin >> n;
        if(!n) break;
        int cnt = 0;
        for(int i=n+1; i<=2*n; i++){
            if(is_prime(i)) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}