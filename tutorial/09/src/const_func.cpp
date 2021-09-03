#include <iostream>

class Coord {
public:
    Coord() = default;
    Coord(int x, int y);
    ~Coord() = default;
    int get_x(void) const;
    int get_y(void) const;
private:
    const int x_, y_;
};

Coord::Coord(int x, int y) : x_{x}, y_{y} {}

int Coord::get_x(void) const { return x_; }
int Coord::get_y(void) const { return y_; }

int main(void)
{
    Coord c1{3,4};
    Coord c2{5,6};

    std::cout << c1.get_x() << ' ' << c1.get_y() << '\n';
    std::cout << c2.get_x() << ' ' << c2.get_y() << '\n';

    return 0;
}
