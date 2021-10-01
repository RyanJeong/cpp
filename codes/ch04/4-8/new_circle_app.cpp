// copy 4-7
#include <iostream>

using namespace std;

class Circle {
    int radius; 
public:
    Circle(); 
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius=r; }
    double getArea(void) { return 3.14*radius*radius; }
}; 

inline Circle::Circle() 
{
    radius=1;
    cout << "생성자 실행, radius = " << radius << endl;
}

inline Circle::Circle(int r) 
{
    radius=r;
    cout << "생성자 실행, radius = " << radius << endl;
}

inline Circle::~Circle() 
{
    cout << "소멸자 실행, radius = " << radius << endl;
}

int main(void) 
{
    while (true) {
        cout << "정수 반지름 입력(음수이면 종료)>> ";
        int radius;
        cin>>radius;
        if (radius < 0) {
            break;
        }

        Circle *p = new Circle(radius); // 동적 객체 생성
        cout << "원의 면적은 " << p->getArea() << endl;

        delete p;
    }

    return 0;
}
