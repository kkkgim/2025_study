#include <iostream>
#include <vector>

using namespace std;

int len;
int n_max, n_min;

vector<int> arr;

char ops[4] = {'+', '-', '*', '/'};
vector<char> op_list;
bool visited[10];

void dfs(int depth,int sum){
    if(len==depth) {
        n_max = max(n_max, sum);
        n_min = min(n_min, sum);
    }
    
    for(int i=0; i<len-1; i++){
        // 방문 안했으면 진행
        if(!visited[i]){
            visited[i]=true;
 
            if(op_list[i]=='+') dfs(depth+1,sum+arr[depth]);
            else if(op_list[i]=='-') dfs(depth+1,sum-arr[depth]);
            else if(op_list[i]=='*') dfs(depth+1,sum*arr[depth]);
            else dfs(depth+1,sum/arr[depth]);

            visited[i]=false;
        }
        

    }
}

int main(){
    cin >> len;

    // 수열
    arr.resize(len);
    for(int i=0; i<len; i++) cin >> arr[i];

    // 연산자
    int n ;
    for(int i=0; i<4; i++){
        cin >> n ;
        op_list.insert(op_list.end(), n, ops[i]);
    } 

    n_max = -1000000000;
    n_min = 1000000000;

    dfs(1,arr[0]);

    cout << n_max << '\n' << n_min;

}