#include <iostream>
#include <string>

using namespace std;

int cnt = 0 ;
int recursion(const string& s, int l, int r){
    cnt ++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int main(){
    int T;
    cin >> T;
    
    string str;
    while(T--){
        cin >> str;
        cnt = 0;
        cout <<  recursion(str,0,str.length()-1) << ' ' << cnt << '\n';
    }   
}