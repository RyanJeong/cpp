#include <iostream>

using namespace std;

struct Struct_circle {
private:
	int radius;
public:
	Struct_circle(int r) { radius = r; }
	double getArea(void); 
};

double Struct_circle::getArea(void) 
{

	return 3.14*radius*radius;
}

int main(void) 
{
	Struct_circle waffle(3);
	cout << "면적은 " << waffle.getArea();

    return 0;
}