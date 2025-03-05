#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen // 과같은함수를만들어서써도됩니다.
#include <string.h>
class MyString
{
    char *string_content;
    int string_length;
    int memory_capacity;

public:
    MyString(char c);
    MyString(const char* str);
    // 복사 생성자
    MyString(const MyString &str);
    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);
    void print() const;
    void println() const;
    MyString &assign(const MyString &str);
    MyString &assign(const char *str);
    char at(int i) const;

    MyString &insert(int loc, const MyString &str);
    MyString &insert(int loc, const char *str);
    MyString &insert(int loc, char c);
    MyString &erase(int loc, int num);
    int find(int find_from, const MyString &str) const;
    int find(int find_from, const char *str) const;
    int find(int find_from, char c) const;
    int compare(const MyString &str) const;
};
MyString::MyString(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char *str)
{
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
    {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString &str)
{
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
    {
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const
{
    for (int i = 0; i != string_length; i++)
    {
        std::cout << string_content[i];
    }
}
void MyString::println() const
{
    for (int i = 0; i != string_length; i++)
    {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}
MyString &MyString::assign(const MyString &str)
{
    if (str.string_length > memory_capacity)
    {
        // 그러면 다시 할당을 해줘야만 한다. delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++)
    {
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}
MyString &MyString::assign(const char *str)
{
    int str_length = strlen(str);
    if (str_length > memory_capacity)
    {
        // 그러면 다시 할당을 해줘야만 한다. delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++)
    {
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity)
    {
        char *prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
}

char MyString::at(int i) const{
    if (i >= string_length || i < 0)
    {
        return 0;
    }
    else
    {
        return string_content[i];
    }
}

MyString &MyString::insert(int loc, const MyString &str){
    // 이는i 의위치바로앞에문자를삽입하게된다. 예를들어서
    // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.
    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc < 0 || loc > string_length)
        return *this;
    if (string_length + str.string_length > memory_capacity){ 
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char *prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 insert 되는 부분 직전까지의 내용을 복사한다. 
        int i;
        for (i = 0; i < loc; i++)
        {
            string_content[i] = prev_string_content[i];
        }
        // 그리고 새롭에 insert 되는 문자열을 넣는다.
        for (int j = 0; j != str.string_length; j++)
        {
            string_content[i + j] = str.string_content[j];
        }
        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다. 
        for (; i < string_length; i++) {
        string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        string_length = string_length + str.string_length;

        return *this;
    }

    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
    for (int i = string_length - 1; i >= loc; i--)
    {
        // 뒤로밀기. 이때원래의문자열데이터가사라지지않게함
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];
    string_length = string_length + str.string_length;
    return *this;
}

MyString &MyString::insert(int loc, const char *str)
{
    MyString temp(str);
    return insert(loc, temp);
}
MyString &MyString::insert(int loc, char c)
{
    MyString temp(c);
    return insert(loc, temp);
}
MyString &MyString::erase(int loc, int num)
{
    // loc 의앞부터 시작해서 num 문자를지운다.
    if (num < 0 || loc < 0 || loc > string_length)
        return *this;
    // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고 // 생각하면 됩니다.
    if (num+loc > string_length){
        std::cout << "exceed string length" << std::endl;
        return *this;
    }
    for (int i = loc + num; i < string_length; i++)
    {
        string_content[i - num] = string_content[i];
    }
    string_length -= num;
    return *this;
}
int MyString::find(int find_from, const MyString &str) const
{
    int i, j;
    if (str.string_length == 0)
        return -1;
    for (i = find_from; i <= string_length - str.string_length; i++)
    {
        for (j = 0; j < str.string_length; j++)
        {
            if (string_content[i + j] != str.string_content[j])
                break;
        }
        if (j == str.string_length)
            return i;
    }

    return -1; // 찾지 못했음
}
int MyString::find(int find_from, const char *str) const
{
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const
{
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::compare(const MyString &str) const
{
    // (*this) - (str) 을 수행해서 그 1, 0, -1 로그 결과를 리턴한다 
    // 1 은(*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열 이같다는의미, -1 은(*this)가 사전식으로 더 앞에 온다는 의미
    for (int i = 0; i < std::min(string_length, str.string_length); i++)
    {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }
    if (string_length == str.string_length)
        return 0;
    // abc 와abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
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

    str1.~MyString();  // 소멸자 호출 (기존 메모리 해제)
    // [placement new] 기존 메모리 주소를 받아, 그 위치에 객체를 생성 
    new (&str1) MyString("abcdef"); 
    MyString str2("abcde");
    std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}
