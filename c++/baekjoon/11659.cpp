#include <iostream>

using namespace std;

int main(){
    // C++ 입출력 최적화
    std::ios_base::sync_with_stdio(false);  
    // `cin` 실행 후 `cout` 자동 flush 방지
    std::cin.tie(NULL);  

    int n, m, x, a, b;
    cin >> n >> m;

    // 수열

    int arr[n+1] ={0};
    for(int i=1; i<=n; i++){
        cin >> x;
        arr[i] = arr[i-1] + x; 
        
    }

    // 합 구하기
    // (1~n+2) - (1~n) = (n+1~n+2)
    for(int i=0; i<m; i++){
        cin >> a >> b; 
        cout << arr[b]-arr[a-1] << '\n';
    }

    return 0;
}