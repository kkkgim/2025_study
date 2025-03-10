#include <iostream>

// 구조체 선언
typedef struct Animal {
    char name[30];
    int age;

    int health;
    int food;
    int clean;
}Animal;

// 초기화
void create_animal(Animal *animal){
    std::cout << "동물의 이름은 ? ";
    std::cin >> animal->name;
    
    std::cout << "동물의 나이는 ? ";
    std::cin >> animal->age;
    
    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;

}
void paly(Animal *animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_pass(Animal *animal){
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_stat(Animal *animal){
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력 : " << animal->health << std::endl;
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결 : " << animal->clean << std::endl;
}

int main() {
    // 포인터는 스택에 있지만, 실제 객체는 힙에 있음
    Animal *list[10];
    int animal_num = 0;

    for(;;){
        std::cout << "1.동물 추가하기" << std::endl;
        std::cout << "2.놀기" << std::endl;
        std::cout << "3.상태보기" << std::endl;

        int input;

        std::cin >> input;

        if (input == 0) {
            std::cout << "프로그램 종료" << std::endl;
            break;  // 반복문 탈출
        }

        switch(input){
            int whos;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            case 2:
                std::cout << "누구랑 놀게 ? " ;
                std::cin >> whos;
                if(whos < animal_num) paly(list[whos]);
                break;
            case 3:
                std::cout << "누구껄 보게 ? " ;
                std::cin >> whos;
                if(whos < animal_num) show_stat(list[whos]);
                break;
        }

        for(int i = 0; i < animal_num; i++){
            one_day_pass(list[i]);
        }
    }
    // list는 배열이 아니고, 포인터 배열로써 각 배열 원소(list[i])가 new로 개별적으로 할당
    // delete[]가 아니라 delete로 하나씩 해제해야함
    for(int i=0; i<animal_num; i++){
        delete list[i];
    }

    return 0;
} 