#include <iostream>
#include <string>

using namespace std;

int main(){
    // C++ 입출력 최적화
    ios::sync_with_stdio(false);  
    // cin 실행 후 cout 자동 flush 방지
    cin.tie(NULL);  

    string S;
    int q;
    cin >> S >> q;

    // 이중배열 선언 및 초기화
    int arr[26][S.length()+1]; 
    for(int i=0; i<26; i++) {
        arr[i][0] = 0;
        if(S[0] == 'a'+i) arr[i][1] = 1;
        else arr[i][1] = 0;
    }

    // 같은 문자가 있으면 + 1 
    for(int i=0; i<26; i++) {
        for(int j=2; j<=S.length(); j++){
            if(S[j-1]=='a'+i) arr[i][j] = arr[i][j-1] + 1;
            else arr[i][j] = arr[i][j-1];
        }       
    }

    char x ; 
    int s, e;
    while(q--){
        cin >> x >> s >> e ;
        cout << arr[x-'a'][e+1] - arr[x-'a'][s] << '\n';
    }
    return 0;
}