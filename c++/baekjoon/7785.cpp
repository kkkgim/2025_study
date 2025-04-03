#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    std::cin >> n;

    set<string> arr;
    string name, status;
    for(int i=0; i<n; i++){
        cin >> name >> status;
        if(status == "enter") arr.insert(name);
        else arr.erase(name);
    }
    // rbegin(), rend() -> 역순 iterator
    for(auto it = arr.rbegin(); it != arr.rend(); it++) {
        cout << *it << '\n';
    }

    return 0;
}