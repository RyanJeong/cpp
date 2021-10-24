// copy 5-6 remove increase(), add readRadius
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

void readRadius(Circle &c) 
{
    int r;
    cout << "정수 값으로 반지름을 입력하세요>>";
    cin>>r; // 반지름 값 입력
    c.setRadius(r); // 반지름 설정

    return;
}

int main(void) 
{
    Circle donut;
    readRadius(donut);
    cout << "donut의 면적 = " << donut.getArea() << endl;

    return 0;
}