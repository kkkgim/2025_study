#include <iostream>
#include <string>
using namespace std;


int main() {
    // C 스타일 입출력과의 동기화 해제 (속도 증가)
    ios::sync_with_stdio(false); 
    // cin과 cout을 분리하여 실행 속도 향상
    cin.tie(NULL); 

    int n,num;
    cin >> n ;
    const int NUM = 10001;
    int arr[NUM] = {0,};

    for(int i=0; i<n; i++){
        cin >> num;
        arr[num]++;
    }
    

    // 정렬된 배열 출력
    for (int i = 0; i < NUM; i++) {
        for(int j=0; j<arr[i]; j++){
            cout << i << '\n';
        }
    }

    return 0;
}