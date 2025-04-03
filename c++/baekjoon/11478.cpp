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

    string str;
    std::cin >> str;
    
    set<string> str_set;
    for(int i=1; i<=str.length(); i++){
        for(int j=0; j+i<=str.length(); j++){
            str_set.insert(str.substr(j,i));
        }
    }
    cout << str_set.size();
    return 0;
}