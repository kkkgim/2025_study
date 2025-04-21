#include <iostream>
#include <vector>

using namespace std;

int n,m;

vector<int> arr;
void dfs(int start, int depth){
    if(depth == m){
        for(int num :arr){
            cout << num << ' ';
        }
        cout << '\n';
        return ;
    }

    for(int i=start; i<=n; i++){
        arr.push_back(i);
        dfs(i, depth+1);
        arr.pop_back();
    }
}
int main(){
    cin >> n >> m;

    dfs(1,0);
    return 0;
}