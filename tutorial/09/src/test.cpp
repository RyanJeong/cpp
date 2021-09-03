#include <iostream>

class Coord {
public:
    Coord();
    Coord(int x, int y);
    ~Coord();
    void print_total_num(void);
private:
    const int x_, y_;
    static int total_num;
};

int Coord::total_num = 0; // Explicit init.

Coord::Coord() : x_{0}, y_{0} { ++total_num; }
Coord::Coord(int x, int y) : x_{x}, y_{y} { ++total_num; }
Coord::~Coord() { --total_num; }

void Coord::print_total_num(void)
{
    std::cout << total_num << '\n';

    return;
}

void foo(void);
void bar(void);

int main(void)
{
    Coord c1{3,4};
    c1.print_total_num();
    foo();
    c1.print_total_num();

    return 0;
}

void foo(void)
{
    Coord c2{5,6};
    c2.print_total_num();
    bar();
    c2.print_total_num();

    return;
}

void bar(void)
{
    Coord c3{7,8};
    c3.print_total_num();

    return;
}