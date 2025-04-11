#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int T;
    cin >> T;
    string nick_name;
    int cnt = 0;
    
    set<string> s_v; 
    
    while(T--){
        cin >> nick_name;
        if(nick_name == "ENTER"){
            cnt += s_v.size();
            s_v.clear();
        } 
        else{
            s_v.insert(nick_name);
        }

    }
    cout << cnt + s_v.size() << '\n';
}