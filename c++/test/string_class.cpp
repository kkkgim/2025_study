#include <iostream>

class string{
    char *str;
    int len;

    public:
        //// ****** 생성자 및 소멸자 ****** ////

        // 1. 문자 n개를 이어붙여서 문자열 생성
        string(char c, int n) {
            len = n;  // 문자열 길이 저장
            str = new char[len + 1];  // 동적 메모리 할당 (널 문자 포함)

            for (int i = 0; i < len; i++) {
                str[i] = c;  // n번 문자 저장
            }
            str[len] = '\0';  // 문자열 끝에 널 문자 추가
        }

        // 2. C 스타일 문자열을 받아서 문자열 생성
        string(const char *s) {
            len = 0;
            while (s[len] != '\0') { 
                len++;
            }

            str = new char[len + 1];  // 동적 메모리 할당 (+1: 널 문자 포함)

            // 문자열 복사 (strcpy 없이)
            for (int i = 0; i < len; i++) {
                str[i] = s[i];
            }
            str[len] = '\0';  // 문자열 끝에 널 문자 추가
        }

        // 3. 복사 생성자 (깊은 복사)
        string(const string &s) {
            len = s.len;
            str = new char[s.len+1];
            for(int i = 0; i < s.len; i++){
                str[i] = s.str[i];
            }
            str[s.len]='\0';
        }

        // 4. 소멸자 (동적 할당 메모리 해제)
        ~string() {
            delete[] str;
        }

        //// ****** 메서드 ****** //// 

        // 5. 문자열 이어붙이기
        void add_string(const string &s) { 
            // temp는 스택 변수라서 함수 종료 시 자동 소멸         
            char *temp = new char[len + s.len + 1]; 

            for(int i=0; i<len; i++){
                temp[i] = str[i];
            }
            for(int i=len; i<len+s.len; i++){
                temp[i] = s.str[i-len];
            }
            temp[len+s.len] = '\0';

            delete[] str;    // 기존 메모리 해제
            str = temp;      // 새로운 메모리 할당
            len += s.len;    // 문자열 길이 갱신
        }


        // 6. 문자열 복사
        void copy_string(const string &s) {
            delete[] str;                 // 기존 메모리 해제
            len = s.len;                 
            str = new char[len+1];
            for(int i=0; i<len; i++){
                str[i] = s.str[i];
            }
            str[len] = '\0';
        }


        // 7. 문자열 길이 반환 
        int strlen() {
            return len;
        }

        // 8. 문자열 출력
        void show() {
            std::cout << str << std::endl;
        }
};

int main() {
    // 문자 'c'를 3번 이어붙이기
    string s1('c', 3);
    s1.show();  // ccc

    // C 스타일 문자열로 생성
    string s2("Hello");
    s2.show();  // Hello

    // 복사 생성자
    string s3(s2);
    s3.show();  // Hello

    // 문자열 이어붙이기
    s1.add_string(s2);
    s1.show();  // cccHello

    // 문자열 복사
    s1.copy_string(s3);
    s1.show();  // Hello

    // 문자열 길이 출력
    std::cout << "문자열 길이: " << s1.strlen() << std::endl;  // 5

    return 0;
}
