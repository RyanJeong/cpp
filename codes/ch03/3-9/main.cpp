#include <iostream> 
using namespace std; 

class Private_access_error {
private:
	int a;
	void f(void);
	Private_access_error();
public:
	int b;
	Private_access_error(int x);
	void g(void);
};

Private_access_error::Private_access_error() : a(1), b(1) { }

Private_access_error::Private_access_error(int x) : a(x), b(x) { }

void Private_access_error::f(void) 
{
	a=5;
	b=5;

    return;
}

void Private_access_error::g(void) 
{
	a=6;
	b=6;

    return;
}

int main(void) 
{
	Private_access_error objA;      // (1)
	Private_access_error objB(100); // (2)
	objB.a = 10; // (3)
	objB.b = 20; // (4)
	objB.f(); // (5)
	objB.g(); // (6)

    return 0;
}