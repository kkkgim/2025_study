#include <iostream>

using namespace std;

int main(){
    int n; 
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i] ;
    }

    // 초기화
    int dp_up[n];
    int dp_down[n];
    for(int i=0; i<n; i++){
        dp_up[i]=1;
        dp_down[i]=1;
    } 

    // 증가하는 부분
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]) dp_up[i] = max(dp_up[i], dp_up[j]+1);
        }
    }

    // 감소하는 부분
    // 증가하는 부분과 같은 인덱스 값에서 바이토닉을 합쳐야함
    // 인덱스 값에서 감소하는 부분의 길이를 알기 위해선 뒤에서 부터 길이 측정
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=i; j--){
            if(arr[i] > arr[j]) dp_down[i] = max(dp_down[i], dp_down[j]+1);
        }
    }

    // 바이토닉 최대 길이 계산
    int max_len = 0;
    for(int i=0; i<n; i++){
        max_len = max(max_len, (dp_up[i]+dp_down[i])-1);
    }
    cout << max_len;
}