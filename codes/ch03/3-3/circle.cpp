#include <iostream> 

using namespace std; 

class Circle {
public:
	int radius;
	Circle(); // 기본 생성자
	Circle(int r); // 매개 변수 있는 생성자
	double getArea(void);
}; 

Circle::Circle() 
{
	radius=1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) 
{
	radius=r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea(void) 
{

	return 3.14*radius*radius;
}

int main(void) 
{
	Circle donut; // 매개 변수 없는 생성자 호출
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30); // 매개 변수 있는 생성자 호출
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;

    return 0;
}