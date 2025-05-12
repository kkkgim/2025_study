#include <iostream>

using namespace std;
int f[1000000];

int fibo(int n){
    f[1]=1;
    f[2]=2;

    for(int i=3; i<=n; i++){
        f[i]=(f[i-1]+f[i-2]) % 15746;       
    }

    return f[n];
}
int main(){

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}