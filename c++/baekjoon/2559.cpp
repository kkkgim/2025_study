#include <iostream>

using namespace std;

int main(){
    // C++ 입출력 최적화
    std::ios_base::sync_with_stdio(false);  
    // cin 실행 후 cout 자동 flush 방지
    std::cin.tie(NULL);  

    int n, k, tmp, max_val = INT32_MIN;
    cin >> n >> k;

    
    int arr[n+1]={0};
    for(int i=1; i<=n; i++){
        cin >> tmp;
        // 누적 합
        arr[i]= arr[i-1] + tmp;

        if(i >= k) max_val = max((arr[i]-arr[i-k]), max_val);
    } 
  
    cout << max_val;
    return 0;
}