#include <iostream>
#include <MyString.h>

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char *str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++){
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString &str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++){
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
    for (int i = 0; i != string_length; i++){
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++){
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

MyString &MyString::assign(const MyString &str) {
    if (str.string_length > memory_capacity){
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++){
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}

MyString &MyString::assign(const char *str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity){
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++){
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}

int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
}

char MyString::at(int i) const{
    if (i >= string_length || i < 0){
        return 0;
    }
    else{
        return string_content[i];
    }
}

MyString &MyString::insert(int loc, const MyString &str) {
    if (loc < 0 || loc > string_length)
        return *this;
    if (string_length + str.string_length > memory_capacity){ 
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char *prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 insert 되는 부분 직전까지의 내용을 복사
        int i;
        for (i = 0; i < loc; i++)
        {
            string_content[i] = prev_string_content[i];
        }
        // 그리고 새롭에 insert 되는 문자열을 넣음
        for (int j = 0; j != str.string_length; j++)
        {
            string_content[i + j] = str.string_content[j];
        }
        // 이제 다시 원 문자열의 나머지 뒷부분을 복사
        for (; i < string_length; i++) {
        string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        string_length = string_length + str.string_length;

        return *this;
    }

    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로
    for (int i = string_length - 1; i >= loc; i--){
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];
    string_length = string_length + str.string_length;

    return *this;
}

MyString &MyString::insert(int loc, const char *str){
    MyString temp(str);
    return insert(loc, temp);
}

MyString &MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString &MyString::erase(int loc, int num){
    if (num < 0 || loc < 0 || loc > string_length)
        return *this;
    if (num+loc > string_length){
        std::cout << "exceed string length" << std::endl;
        return *this;
    }
    for (int i = loc + num; i < string_length; i++){
        string_content[i - num] = string_content[i];
    }
    string_length -= num;
    return *this;
}

int MyString::find(int find_from, const MyString &str) const{
    int i, j;
    if (str.string_length == 0)
        return -1;
    for (i = find_from; i <= string_length - str.string_length; i++){
        for (j = 0; j < str.string_length; j++){
            if (string_content[i + j] != str.string_content[j])
                break;
        }
        if (j == str.string_length)
            return i;
    }
    return -1; // 찾지 못했음
}

int MyString::find(int find_from, const char *str) const{
    MyString temp(str);
    return find(find_from, temp);
}

int MyString::find(int find_from, char c) const{
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString &str) const {
    for (int i = 0; i < std::min(string_length, str.string_length); i++)
    {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }
    if (string_length == str.string_length)
        return 0;

    else if (string_length > str.string_length)
        return 1;
    return -1;
}
int main(){
    MyString str1("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str1.find(0, "very") << std::endl;
    std::cout << "Location of second <very> in the string : " << str1.find(str1.find(0, "very") + 1, "very") << std::endl;

    std::cout << "erase 10, 5: " ;
    str1.erase(1,100).println();

    // 소멸자 호출 (기존 메모리 해제)
    str1.~MyString();  
    // [placement new] 기존 메모리 주소를 받아, 그 위치에 객체를 생성 
    new (&str1) MyString("abcdef"); 
    MyString str2("abcde");
    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}
