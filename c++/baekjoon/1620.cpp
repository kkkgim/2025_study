#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool isNumber(const string &str) {
    for (char c : str) {
        if (!isdigit(c)) return false; 
    }

    // 비어있으면 1, 안비어있으면 0
    return !str.empty();  
}

int main() {
    // C 스타일 입출력과의 동기화 해제
    ios::sync_with_stdio(false); 
    // cin과 cout을 분리하여 실행 속도 향상
    cin.tie(NULL); 

    unsigned int n,m;
    std::cin >> n >> m;

    map<int,string> name_map;
    map<string,int> num_map;
    string name;
    for(int i=0; i<n; i++){
        cin >> name ;
        name_map.insert({i+1,name});
        num_map.insert({name,i+1});
    }

    for(int i=0; i<m; i++){
        cin >> name ;
        if(isNumber(name)){
            int num = stoi(name);
            cout << name_map[num] << '\n';
        }
        else cout << num_map[name] << '\n';

    }

    return 0;
}