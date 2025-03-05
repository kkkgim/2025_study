#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;

    public:
        Date(int year, int month, int day){
            year_=year;
            month_=month;
            day_=day;
        };
        Date() {
            year_=2021;
            month_=10;
            day_=21;
        };
        void SetDate(int year, int month, int day);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

        void ShowDate(){
            std::cout << year_ << "년 " <<  month_ << "월 " << day_ << "일" << std::endl;
        };
};

bool IsLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            return true; // 윤년
        }
    }
    return false; // 평년
}

void Date::SetDate(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
};

void Date::AddDay(int inc){
    int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    day_ += inc;
    
    if (IsLeapYear(year_)) {
        days_in_month[1] = 29;
    }

    while (day_ > days_in_month[month_ - 1]) {
        day_ -= days_in_month[month_ - 1];   // 남은 일수 계산
        Date::AddMonth(1);                   // 다음 달로 이월

        // 다음 달로 넘어갔을 때 윤년이면 2월 29일로 수정
        if (month_ == 2 && IsLeapYear(year_)) {
            days_in_month[1] = 29;
        } else {
            days_in_month[1] = 28;
        }
    }
}

void Date::AddMonth(int inc){
    month_ += inc;
    while (month_ > 12) {
        month_ -= 12;
        year_++;
    }
};

void Date::AddYear(int inc){ year_ += inc; }

int main(){
    Date day1(2022,1,5);
    Date day2 = Date(2022,3,8);
    Date day3;

    day1.ShowDate();
    day2.ShowDate();
    day3.ShowDate();

    return 0;
}