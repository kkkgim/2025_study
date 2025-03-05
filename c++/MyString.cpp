#include <iostream>

class MyString{
    char* string_content;
    int string_length;
    int memory_capacity;

    public:
        MyString(int capacity);
        MyString(char* str);
        MyString(const MyString& str);

        ~MyString();

        int length() const;
};

MyString::MyString(int capacity){
    
}