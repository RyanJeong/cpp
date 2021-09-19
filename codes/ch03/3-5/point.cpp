#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point();
	Point(int a, int b);
	void show(void) { cout << "(" << x << ", " << y << ")" << endl; }
};

// 멤버 초기화 리스트 (constructor member initializer list)
Point::Point() : Point(0,0) { } // Point(int a, int b) 생성자 호출

Point::Point(int a, int b) : x(a),y(b) { }

int main(void) 
{
	Point origin;
	Point target(10,20);
	origin.show();
	target.show();

	return 0;
}