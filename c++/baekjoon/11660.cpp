#include <iostream>

using namespace std;

int psum[1025][1025];

int main(){
    // C++ 입출력 최적화
    ios::sync_with_stdio(false);
    // cin 실행 후 cout 자동 flush 방지
    cin.tie(NULL);  

    int n,m, x;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> x; 
            // psum[i][j] = 위까지 합 + 왼쪽까지 합 - 겹치는 부분 + 현재 값
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + x;
        } 
    }
    
    int x1, y1, x2, y2;
    while(m--){
        cin >> x1 >> y1 >> x2 >> y2;
        // 마지막 위치의 누적합 - 왼쪽 누적 합 - 위쪽 누적 합 + 겹치는 부분
        cout << psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1] << '\n';
    }

    return 0;
}