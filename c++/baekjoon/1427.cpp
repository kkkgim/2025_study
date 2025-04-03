#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n ;
    int arr[10] = {0,};

    while(n){
        arr[n%10]++;
        n = n/10;
    }
    
    // 정렬된 배열 출력
    for (int i = 9; i >= 0; i--) {
        for(int j=0; j<arr[i]; j++) cout << i ;
    }

    return 0;
}