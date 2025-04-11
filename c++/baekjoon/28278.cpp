#include <iostream>
#include <vector>

using namespace std;

class stack{
    vector<int> v;

    public:
        void push(int x){
            v.push_back(x);
        };

        void pop() {
            if (!v.empty()) {
                cout << v.back() << '\n';
                v.pop_back();
            } else {
                cout << -1 << '\n';
            }
        }

        void size() {
            cout << v.size() << '\n';
        }

        void empty() {
            cout << (v.empty() ? 1 : 0) << '\n';
        }  

        void top() {
            if (!v.empty()) {
                cout << v.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int x,y;
    
    stack st;
    while(n--){
        cin >> x;

        switch(x){
            case 1:
                cin >> y;
                st.push(y);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.size();
                break;
            case 4:
                st.empty();
                break;
            case 5:
                st.top();
                break;
        }
    }
    return 0;
} 