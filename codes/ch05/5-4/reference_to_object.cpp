// copy 5-2, remove getCircle
#include <iostream>

using namespace std;

class Circle {
private:
    int radius; 
public:
    Circle(); 
    Circle(int r);
    ~Circle();
    // inline
    double getArea()  { return 3.14*radius*radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
}; 

Circle::Circle() 
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;

    return;
}

Circle::Circle(int radius) 
{
    this->radius = radius;
    cout << "생성자 실행 radius = "  << radius << endl;

    return;
}

Circle::~Circle() 
{
    cout << "소멸자 실행 radius = " << radius << endl;

    return;
}


void increase(Circle c) 
{
    int r = c.getRadius();
    c.setRadius(r+1);

    return;
}

int main(void) 
{
    Circle circle;
    Circle &refc = circle; 
    refc.setRadius(10);
    cout << refc.getArea() << " " << circle.getArea() << endl; // 두 호출은 동일 객체에 대한 호출

    return 0;
}