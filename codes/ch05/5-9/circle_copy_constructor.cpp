// copy 5-7 , add copy constructor(Circle(const Circle& c);), remove readRadius
#include <iostream>

using namespace std;

class Circle {
private:
    int radius; 
public:
    Circle(); 
    Circle(int r);
    Circle(const Circle& c); // 복사 생성자 선언
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

Circle::Circle(const Circle& c) 
{ // 복사 생성자 구현
    this->radius = c.radius;
    cout << "복사 생성자 실행 radius = " << radius << endl;

    return;
}

Circle::~Circle() 
{
    cout << "소멸자 실행 radius = " << radius << endl;

    return;
}

int main(void) 
{
    Circle src(30); // src 객체의  보통 생성자 호출
    Circle dest(src); // dest 객체의 복사 생성자 호출

    cout << "원본의 면적 = " << src.getArea() << endl;
    cout << "사본의 면적 = " << dest.getArea() << endl;

    return 0;
}
