#include <iostream>

using namespace std;

long long fact(int num){
    if(num<=1) return 1;
    return num * fact(num-1);

}

int main(){
    int n ;
    cin >> n;
    long long x = fact(n);
    cout << x;

    return 0;
}