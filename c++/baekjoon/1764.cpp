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

    int n,m;
    std::cin >> n >> m;
    
    set<string> no_listen;
    set<string> no_see;
    string name;
    for(int i=0; i<n; i++){
        cin >> name ;
        no_listen.insert(name);
    }

    for(int i=0; i<m; i++){
        cin >> name ;
        no_see.insert(name);
    }

    // C++20  부터 사용 가능
    // no_listen.merge(no_see);
    // no_see ==> 교집합

    // 교집합 계산
    set<string> result;
    for (string name : no_listen) {
        if (no_see.count(name)) {
            result.insert(name);
        }
    }
    cout << result.size() << '\n';
    for (string name : result) cout << name << '\n';
        
    return 0;
}