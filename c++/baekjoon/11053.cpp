#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; 
    cin >> n ;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
        

    int dp[n];
    fill_n(dp,n,1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+1);
        }

    }

    int max_cnt =0;
    for(int i=0; i<n; i++){
        max_cnt = max(max_cnt, dp[i]);
    }

    cout << max_cnt;
}