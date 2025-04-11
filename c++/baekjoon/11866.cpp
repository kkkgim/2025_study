#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    bool arr[n] = {true,};
    for(int i=0; i<n; i++) arr[i] = true;
    queue<int> q;

    int idx = -1;
    int chk_idx = 0;
    while(q.size() < n){
        idx++;
        if(idx >= n) idx=0;
        if(arr[idx]){
            chk_idx++;
        }

        if(chk_idx==k){
            arr[idx]=false;
            q.push(idx+1);
            chk_idx=0;
        }        
    }

    cout << "<";
    while(!q.empty()){
        cout << q.front();
        if(q.size()>1) cout << ", ";
        q.pop();
    }
    cout << ">";


    return 0;
}
