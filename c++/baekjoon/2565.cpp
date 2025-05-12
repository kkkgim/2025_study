#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, x, y; 
    cin >> n;

    // 데이터 삽입
    set<pair<int,int>> tmp_arr;     
    for(int i=0; i<n; i++){
        cin >> x >> y;
        tmp_arr.insert({x,y});   
    }  

    // 전깃줄이 정렬되어 있는 배열 만듬
    int arr[n];
    int idx = 0;
    for(auto data : tmp_arr) arr[idx++] = data.second;

    // 정렬된 배열에서 제일 긴 수열 구함
    int dp[n] = {1};
    fill(dp, dp+n, 1);

    int max_len = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+1);
        }
        max_len=max(max_len,dp[i]);
    }
    
    // 총 길이에서 제일 긴 수열의 길이 제거
    cout << n - max_len ;
    
}