
class MyString {
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

    // 연산자 오버로딩
    bool operator==(MyString& str){
        return !compare(str);
    }
};