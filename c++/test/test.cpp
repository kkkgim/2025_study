#include <iostream>
using namespace std;

void goo(int n, double d, const char* s)
{
    cout << "goo : " << n << " " << d << " " << s << endl;
}

int hoo(int a) { return -a; }

int print(int a)
{
    cout << a << ", ";
    return 0;
}

template<typename ... Types>
void foo(Types ... args)
{
    int x[] = { args... }; // Pack expansion
    for (auto n : x)
        cout << n << endl;

    //print(args); // Error(함수 호출 인자 or list 초기화가 아님)
    //print(args...); // Error(함수 호출 인자 or list 초기화가 아님)
    //print(args)...; // Error(함수 호출 인자 or list 초기화가 아님)

    // 배열 이용
    int ea[] = { 0, (print(args), 0)... };


}

int main()
{
    foo(1, 2, 3);
     // Types : int, int, int
     // args : 1, 2, 3
}