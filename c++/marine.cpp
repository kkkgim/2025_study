#include <string.h>
#include <iostream>

class Marine { 
    int hp;
    int coord_x, coord_y; 
    int damage;
    bool is_dead;
    char* name; // 마린 이름
    // 마린 체력 // 마린 위치 // 공격력
    public:
        Marine();
        Marine(int x, int y, const char* marine_name); 
        Marine(int x, int y);
        ~Marine();
        int attack();
        void be_attacked(int damage_earn); void move(int x, int y);

        void show_status(); // 상태를 보여준다.
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
    // 동적할당 해줌
    name = new char[strlen(marine_name) + 1]; 
    strcpy(name, marine_name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
   coord_x = x;
   coord_y = y;
   hp = 50;
   damage = 5;
   is_dead = false;
   name = NULL;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y; }
    int Marine::attack() { return damage; } void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true; }
    void Marine::show_status() {
    std::cout << " *** Marine : " << name << " ***" << std::endl; 
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 ! " << std::endl; 
    // 생성자에서 동적할당하여 delete 필수 
    if (name != NULL) {
        delete[] name; 
    }
}

int main() {
    Marine* marines[100];
    // 동적할당 해줌
    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1"); 
    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();
    // 메모리 해제 필수
    delete marines[0];
    delete marines[1]; 
}