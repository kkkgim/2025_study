#include <iostream>

class FriendExample;

class OtherClass{
    public:
        void showSecret(const FriendExample& obj);
};

class FriendExample {
    private:
        int secretValue;
    public:
        FriendExample(int value);
        void showValue() const;
        friend class OtherClass;
        // 특정 함수만 friend로 선언
        friend void accessSecret(const FriendExample& obj);
};

FriendExample::FriendExample(int value) : secretValue(value) {}

void FriendExample::showValue() const {
    std::cout << "Secret Value: " << secretValue << std::endl;
}

// friend 함수 정의 (클래스 외부)
void accessSecret(const FriendExample& obj) {
    std::cout << "[Friend Function] Secret Value: " << obj.secretValue << std::endl;
}

void OtherClass::showSecret(const FriendExample& obj) {
    std::cout << "OtherClass accessing secret: " << obj.secretValue << std::endl;
}

