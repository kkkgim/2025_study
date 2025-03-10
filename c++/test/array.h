#include <iostream>

class Array {
    int* data;      // 1D 배열로 저장
    int* sizes;     // 각 차원의 크기를 저장하는 배열
    int dimensions; // 차원 개수

    public:
        template<typename ... Types>
        Array(Types ... args);
        ~Array();

        void print();
        // void operator[](int x);
};

template<typename ... Types>
Array::Array(Types... args) : dimensions(sizeof...(args)), totalSize(1) {
    // 차원 크기를 배열에 저장
    sizes = new int[dimensions];
    int idx = 0;
    int temp[] = { args... };  // 가변 인자 배열로 저장

    for (int value : temp) {
        sizes[idx++] = value;
        totalSize *= value;  // 전체 크기 계산
    }
    

    // 1D 배열 동적 할당
    data = new int[totalSize];

    // 초기값 설정 (예제)
    for (int i = 0; i < totalSize; i++) {
        data[i] = i + 1;
    }

    std::cout << "Array (";
    for (int i = 0; i < dimensions; i++) {
        std::cout << sizes[i] << (i == dimensions - 1 ? ")" : " x ");
    }
    std::cout << " created.\n";
}


Array::~Array(){
    for(int i=0;i<length;i++){
        delete[] arr[i];
    } 
}


int main(){
    Array a(2,2,2);
}
