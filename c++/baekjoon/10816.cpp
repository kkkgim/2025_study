#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    // C 스타일 입출력과의 동기화 해제
    ios::sync_with_stdio(false); 
    // cin과 cout을 분리하여 실행 속도 향상
    cin.tie(NULL); 

    int n,m,x;
    std::cin >> n ;

    map<int,int> card_map;
    for(int i=0; i<n; i++){
        cin >> x ;
        if(!card_map.count(x)) card_map.insert({x,1});
        else card_map[x]++;
    }

    std::cin >> m ;
    for(int i=0; i<m; i++){
        cin >> x ;
        cout << card_map[x] << ' ';
    }

    return 0;
}