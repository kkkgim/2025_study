#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<char>>& arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] ;
        }
        cout << '\n';
    }
}
void replace(vector<vector<char>>& arr, long x, long y,int size){
    if(size==1) return;

    int diff = size/3;

    for(int i=x+diff; i<x+2*diff; i++){
        for(int j=y+diff; j<y+2*diff; j++){
            arr[i][j] = ' ';  
        } 
    }

    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            if (dx == 1 && dy == 1) continue; // 가운데는 건너뜀
            replace(arr, x + dx * diff, y + dy * diff, diff);
        }
    }
     
}

int main(){
    int n;
    cin >> n;

    vector<vector<char>> arr(n,vector<char>(n,'*'));
    replace(arr, 0 , 0, n);

    print(arr);
    return 0;
}

