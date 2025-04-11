#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int T;
    cin >> T;
    string name1, name2;
    int cnt = 0;
    
    set<pair<string,bool>> s_v; 
    s_v.insert({"ChongChong",true});

    while(T--){
        cin >> name1 >> name2;

        if(s_v.find({name1, true}) != s_v.end()){
            s_v.insert({name2,true});
        }
        else if(s_v.find({name2, true}) != s_v.end()){
            s_v.insert({name1,true});
        }
    }

    cout << s_v.size() << '\n';
}