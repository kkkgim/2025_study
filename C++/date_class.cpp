#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;

    public:
    void SetDate(int year, int month, int day);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    void ShowDate();
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

void Date::ShowDate() {
    std::cout << year_ << "년 " <<  month_ << "월 " << day_ << "일" << std::endl;
}

int main(){
    Date date;
    date.SetDate(2023, 12, 30);
    date.ShowDate();  // 2023년 12월 30일
    date.AddDay(5);
    date.ShowDate();  // 2024년 1월 4일 (2024년은 윤년)
    
    date.AddDay(365);
    date.ShowDate();  // 2025년 1월 4일

    date.AddMonth(14);
    date.ShowDate();  // 2026년 3월 4일
    
    date.SetDate(2024, 2, 28);
    date.AddDay(1);
    date.ShowDate();  // 2024년 2월 29일 (윤년)
    
    date.AddDay(1);
    date.ShowDate();  // 2024년 3월 1일
    
    date.SetDate(2023, 2, 28);
    date.AddDay(1);
    date.ShowDate();  // 2023년 3월 1일 (평년)

    date.SetDate(2023, 12, 31);
    date.AddDay(365);
    date.ShowDate();  // 2024년 12월 31일
    return 0;
}