#include <iostream>

class Array;  // 전방 선언

// 🔹 다차원 인덱싱을 위한 보조 클래스
class ArrayAccessor {
    Array& arr;   // 원본 배열 참조
    int index;    // 현재 접근한 차원의 인덱스
    int depth;    // 현재 차원 (0부터 시작)

public:
    ArrayAccessor(Array& array, int idx, int d) : arr(array), index(idx), depth(d) {}

    ArrayAccessor operator[](int idx);
    operator int&();  // 마지막 차원에서 int& 반환
};

// 🔹 다차원 배열을 관리하는 클래스
class Array {
    int* data;      // 1D 배열로 저장
    int* sizes;     // 각 차원의 크기를 저장하는 배열
    int dimensions; // 차원 개수
    int totalSize;  // 전체 요소 개수

public:
    template<typename... Types>
    Array(Types... args);

    ~Array();

    void print();

    ArrayAccessor operator[](int index) { return ArrayAccessor(*this, index, 0); }

    friend class ArrayAccessor;  // ArrayAccessor가 private 멤버 접근 가능
};

// 🔹 생성자: 가변 인자로 차원 크기 받음
template<typename... Types>
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

    // 초기값 설정
    for (int i = 0; i < totalSize; i++) {
        data[i] = i + 1;
    }

    std::cout << "Array (";
    for (int i = 0; i < dimensions; i++) {
        std::cout << sizes[i] << (i == dimensions - 1 ? ")" : " x ");
    }
    std::cout << " created.\n";
}

// 🔹 소멸자: 동적 할당한 메모리 해제
Array::~Array() {
    delete[] data;
    delete[] sizes;
    std::cout << "Array destroyed.\n";
}

// 🔹 배열 요소 출력
void Array::print() {
    std::cout << "Array elements: ";
    for (int i = 0; i < totalSize; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// 🔹 다차원 인덱싱 연산자 오버로딩 (ArrayAccessor)
ArrayAccessor ArrayAccessor::operator[](int idx) {
    return ArrayAccessor(arr, index * arr.sizes[depth + 1] + idx, depth + 1);
}

// 🔹 마지막 차원에서 `int&` 반환
ArrayAccessor::operator int&() {
    return arr.data[index];
}

int main() {
    Array a(2, 2, 2);  // 2x2x2 배열 생성
    a.print();

    // 🔹 다차원 인덱싱 지원
    a[1][1][1] = 99;  
    std::cout << "Modified element a[1][1][1]: " << a[1][1][1] << std::endl;

    a.print();

    return 0;
}
