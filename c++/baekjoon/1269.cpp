#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    // C 스타일 입출력과의 동기화 해제
    ios::sync_with_stdio(false); 
    // cin과 cout을 분리하여 실행 속도 향상
    cin.tie(NULL); 

    int n,m,x;
    std::cin >> n >> m;
    
    set<int> set_1;
    set<int> set_2;
    
    for(int i=0; i<n; i++){
        cin >> x ;
        set_1.insert(x);
    }

    for(int i=0; i<m; i++){
        cin >> x ;
        set_2.insert(x);
    }

    // 합집합 개수 count
    int cnt = 0;
    for (int num : set_1) {
        if(set_2.count(num)) {
            cnt++;
        }
    }

    cout << (set_1.size() + set_2.size() - (cnt*2)) ;

        
    return 0;
}