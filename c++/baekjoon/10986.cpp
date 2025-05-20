#include <iostream>

using namespace std;

int main(){
    // C++ 입출력 최적화
    ios::sync_with_stdio(false);  
    // cin 실행 후 cout 자동 flush 방지
    cin.tie(NULL);  

    int n,m;
    cin >> n >> m;

    // 나머지 배열 초기화
    long long arr[m] = {0}; 
    for (int i=0; i<m; i++) {
        arr[i]=0;
    }

    long long sum = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum += x;

        arr[sum%m]++;    
    }

    // 나머지가 0인 경우는 독립적으로도 count 가능
    long long cnt = arr[0];
    for (int i=0; i<m; i++) {
        if(arr[i]!=0) cnt += (arr[i] * (arr[i] - 1)) / 2;
    }

    cout << cnt;
    return 0;
}