#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    while(n--){
        string str;
        cin >> str;

        vector<char> v ;
        v.push_back(str[0]);
        for(int i=1; i<str.length(); i++){
            if(v.back()=='(' && str[i]==')') v.pop_back();
            else v.push_back(str[i]);
        }

        if(v.size()) cout << "NO" << '\n';
        else cout << "YES" << '\n' ; 
    }
    return 0;
} 