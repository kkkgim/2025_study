#include <iostream>
#include <vector>

class Array {
    int* data;        // 1D 배열로 저장
    int* sizes;       // 각 차원의 크기 저장
    int dimensions;   // 차원 개수
    int totalSize;    // 전체 요소 개수
    std::vector<int> indices;  // 현재까지 받은 인덱스 저장

    // 인덱스 계산
    int computeIndex() {
        if (indices.size() != dimensions) {
            std::cerr << "Error: Invalid number of indices!\n";
            exit(1);
        }

        int idx = 0;
        int multiplier = 1;

        for (int i = dimensions - 1; i >= 0; i--) {
            idx += indices[i] * multiplier;
            // 차원의 크기만큼 multiplier 설정 
            multiplier *= sizes[i];
        }
        return idx;
    }

public:
    template<typename... Types>
    Array(Types... args);
    ~Array();

    // [] 연산자 오버로딩: 매개변수로 받은 모든 인덱스 값을 저장
    Array& operator[](int idx) {
        indices.push_back(idx);  // 현재 인덱스를 저장
        return *this; // 해당 객체를 반환
    }

    // 대입 연산자 오버로딩: 최종 인덱스에 해당하는 위치에 값을 할당
    void operator=(int num) {
        int flatIndex = computeIndex();
        data[flatIndex] = num;
        indices.clear();
    }
    // 함수 호출 연산자 오버로딩: 최종 인덱스에 해당하는 위치의 값을 반환
    int& operator()() {
        int flatIndex = computeIndex();
        indices.clear();
        return data[flatIndex];
    }
};

// 생성자: 가변 인자로 차원 크기 받음
// c++11 이상에서 사용 가능
template<typename... Types>
Array::Array(Types... args) : dimensions(sizeof...(args)), totalSize(1) {
    sizes = new int[dimensions];
    int idx = 0;
    int temp[] = { args... };

    for (int value : temp) {
        sizes[idx++] = value;
        totalSize *= value;
    }
    data = new int[totalSize];
    for (int i = 0; i < totalSize; i++) {
        data[i] = i + 1;  // 예제 데이터
    }

    std::cout << "Array (";
    for (int i = 0; i < dimensions; i++) {
        std::cout << sizes[i] << (i == dimensions - 1 ? ")" : " x ");
    }
    std::cout << " created.\n";
}

// 소멸자: 동적 메모리 해제
Array::~Array() {
    delete[] data;
    delete[] sizes;
    std::cout << "Array destroyed.\n";
}

int main() {
    Array a(2, 2, 3);  // 2x2x3 배열 생성
    std::cout << a[1][1][2]() << std::endl;  
    a[1][1][2] = 3; // 대입 
    std::cout << a[1][1][2]() << std::endl;  

    return 0;
}
