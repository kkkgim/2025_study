#include <iostream>
#include <vector>

using namespace std;

// a:기존, b:보조, c:목표
void hanoi(int n, int a, int b, int c){
    if(n==1) cout << a << ' ' << c << '\n';
    else{
        hanoi(n-1, a, c, b);
        cout << a << ' ' << c << '\n';
        hanoi(n-1, b, a, c);
    }

}
int main(){
    int n;
    cin >> n;
    
    cout << (1<<n)-1 << '\n';
    hanoi(n,1,2,3);

    return 0;
}

