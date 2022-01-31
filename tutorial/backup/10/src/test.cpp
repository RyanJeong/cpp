#include <iostream>

class Test {
public:
    Test() = default;
    void set_val(int x, int y);
    Test& get_t(void);
private:
    int _x, _y;
};

void Test::set_val(int x, int y)
{
    this->_x=x;
    this->_y=y;

    return;
}

Test& Test::get_t(void)
{

    return *this;
}

int main(void)
{

    return 0;
}