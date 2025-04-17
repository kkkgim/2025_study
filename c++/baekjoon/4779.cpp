#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void replace(string &s, long left , long right){
    long diff = ((right-left)/3) ;

    if(diff>0){
        for(long i=left+diff; i<right-diff; i++){
            s[i] = ' ';
        }
        replace(s, left, left+diff);
        replace(s, right-diff, right);
    }
}

int main(){
    int n;
    
    while (cin >> n){
        long len = 1;
        for(int i = 0; i < n; i++) len *= 3;

        string cantore(len,'-');
        replace(cantore,0,cantore.length());
        cout << cantore << '\n';
    }
  
    return 0;
}

