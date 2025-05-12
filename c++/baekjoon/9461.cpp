#include <iostream>

using namespace std;
long long f[101];

void P(int n){
    for(int i=4; i<=n; i++){
        f[i]=(f[i-2]+f[i-3]);       
    }
}

int main(){

    int T;
    cin >> T;
    f[1]=1;
    f[2]=1;
    f[3]=1;
    P(101);

    while(T--){
        int n ;
        cin >> n;
        cout << f[n] <<'\n';
    }
    return 0;
}