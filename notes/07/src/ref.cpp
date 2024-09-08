#include <iostream>

class Test {
public:
    Test(int x);
    int& access_x(void);
    void print_x(void);
private:
    int x_;
};

Test::Test(int x) : x_{x} {}

int& Test::access_x(void)
{

    return this->x_;
}
void Test::print_x(void)
{
    std::cout << x_ << '\n';

    return;
}

int main(void)
{
    Test t{5};
    t.print_x(); // 5

    int& i = t.access_x();
    i=3;
    t.print_x(); // 3

    int j = t.access_x();
    j=4;
    t.print_x(); // 3

    t.access_x()=7;
    t.print_x(); // 7

    return 0;
}