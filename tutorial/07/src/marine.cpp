#include <iostream>
#include <string.h>

class Marine {
public:
    Marine(void);              
    Marine(int x, int y);  
    Marine(int x, int y, char* marine_name);  
    ~Marine(void);
    int attack(void);
    void be_attacked(int damage_earn);
    void move(int x, int y);
    void show_status(void); 
private:
    int hp_;              
    int coord_x_, coord_y_; 
    int damage_;           
    bool is_dead_;
    char* name_;
};

Marine::Marine(void) 
    : hp_{50}, coord_x_{0}, coord_y_{0}, damage_{5}, is_dead_{false}, name_{NULL} {}
Marine::Marine(int x, int y) 
    : hp_{50}, coord_x_{x}, coord_y_{y}, damage_{5}, is_dead_{false}, name_{NULL} {}
Marine::Marine(int x, int y, char* marine_name)
    : hp_{50}, coord_x_{x}, coord_y_{y}, damage_{5}, is_dead_{false}, name_{NULL} 
{
    name_ = new char[strlen(marine_name)+1];
    strcpy(name_,marine_name);

    return;
}
Marine::~Marine(void)
{
    if (name_!=NULL) {
        std::cout << name_ << " 의 소멸자 호출 ! " << std::endl;
        delete[] name_;
    }

    return;
}

void Marine::move(int x, int y) {
    coord_x_=x;
    coord_y_=y;

    return;
}

int Marine::attack(void) 
{ 
    
    return damage_; 
}

void Marine::be_attacked(int damage__earn) 
{
    hp_-=damage__earn;
    if (hp_<=0) {
        is_dead_=true;
    }

    return;
}
void Marine::show_status(void) 
{
    std::cout << " *** Marine : " << name_ << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x_ << " , " << coord_y_ << " ) " << std::endl;
    std::cout << " HP : " << hp_ << std::endl;

    return;
}

int main(void) 
{
    Marine* marines[100];

    marines[0] = new Marine{2,3,(char*) "Marine 2"};
    marines[1] = new Marine{3,5,(char*) "Marine 1"};

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];

    return 0;
}