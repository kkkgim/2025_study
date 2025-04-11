#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    while(true){
        getline(cin, str);
        if(str==".") break;

        vector<char> v ;
        for (char ch : str) {
            if (ch == '(' || ch == '[') {
                v.push_back(ch);
            }
            else if(ch ==')'){
                if(!v.empty() && v.back() == '(') v.pop_back();
                else{
                    v.push_back(ch);
                    break;
                }
            }
            else if(ch ==']'){
                if(!v.empty() && v.back() == '[') v.pop_back();
                else{
                    v.push_back(ch); 
                    break;
                } 
            }
        }

        if(v.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n' ; 
    }
    return 0;
} 