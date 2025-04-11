#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    deque<pair<int,int>> dq;
    for(int i=0; i<n; i++){
        cin >> x;
        dq.push_back({i+1,x});
    }

    int idx=0;
    while(!dq.empty()){
        if(idx>0){
            for(int i=0; i<idx-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            } 
        }
        else if(idx<0){
            for(int i=0; i>idx; i--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        cout << dq.front().first << ' ' ;
        idx = dq.front().second;
        dq.pop_front();

    }

    return 0;
}
