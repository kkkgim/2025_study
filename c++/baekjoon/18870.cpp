#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n ;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // 정렬 및 중복제거
    vector<int> dict(arr);
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()),dict.end());

    /* 시간 초과 
     * find() 함수의 시간 복잡도는 O(N)
     * find() 를 N번 반복하니까 O(N²) 
     * 
        // 해당 인덱스 값 출력
        for(int i=0; i<n; i++){
            auto it = find(dict.begin(),dict.end(),arr[i]);    
            cout << it - dict.begin() << ' ';
        }

    */

    // 인덱스 값 출력
    for (int i = 0; i < n; i++) {
        cout << lower_bound(dict.begin(), dict.end(), arr[i]) - dict.begin() << ' ';
    }


    return 0;
}