#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n, k; 
    cin >> n >> k;

    long long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i] ;
    }

    long long x = 0;
    for(int i=n; i>0; i--){
        if(arr[i-1] <= k){
            x += k / arr[i-1] ;
            k =  k % arr[i-1] ;
        };
        if(k==0) break;
    }
    cout << x ;
}