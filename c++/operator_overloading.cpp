#include <iostream>

class String {
    char* txt ;
    int len ;
    public:
        String(const char* str){
            len = strlen(str);
            txt = new char[len];
            for(int i=0; i<len; i++){
                txt[i] = str[i];
            }
        }
        ~String(){delete[] txt;}

        bool operator==(String& str){
            if(len != str.len){ return false; }
            for (int i = 0; i < len; i++){
                if (txt[i] != str.txt[i]){ return false; }
            }
            return true;
        }


};

int main(){
    String str_data("make data");
    String str_data2("make data2");
    String str_data3("make data2");

    std::cout << "str_data2==str_data " ;
    if (str_data2==str_data)
        std::cout << "둘은 같다" << std::endl;
    else
        std::cout << "둘은 다르다" << std::endl;
}