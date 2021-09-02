#include <iostream>

class Animal {
public:
    void set_animal(int food, int weight);
    void increase_food(int num);
    void view_state(void);
private:
    int food_;
    int weight_;
};  // semocolon!

void Animal::set_animal(int food, int weight)
{
    food_=food;
    weight_=weight;

    return;
}

void Animal::increase_food(int num)
{
    food_+=num;
    weight_+=num/7;

    return;
}

void Animal::view_state(void)
{
    std::cout << "The animal's food: " << food_ << std::endl;
    std::cout << "The animal's weight: " << weight_ << std::endl;

    return;
}

int main(void)
{
    Animal cat;
    cat.set_animal(100, 10);
    cat.increase_food(10);
    cat.view_state();

    return 0;
} 