// copy 5-2
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

Circle getCircle() 
{
    Circle tmp(30);

    return tmp; // 객체 tmp을 리턴한다.
}

int main(void) 
{
    Circle c; // 객체가 생성된다. radius=1로 초기화된다.
    cout << c.getArea() << endl;

    c = getCircle();
    cout << c.getArea() << endl;
    
    return 0;
}