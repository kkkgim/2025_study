#include <iostream>
#include <set>
#include <cmath>

using namespace std;

long get_decimal(long num){
    long i = max(num,2L);
    while(true){
        bool isPrime = true;
        for(long j=2; j <= sqrt(i); j++){
            if(i%j==0){
                isPrime=false;
                break;
            } 
        }
        if(isPrime) return i;
        i++;
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long n,num;
    cin >> n;
    
    while(n--){
        cin >> num;
        cout << get_decimal(num) << '\n';
    }
    
    return 0;
}