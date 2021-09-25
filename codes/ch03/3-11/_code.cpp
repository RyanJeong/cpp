#ifdef BLOCK
#include <iostream>

using namespace std;

class Adder {
	int op1, op2;
public:
	Adder(int a, int b);
	int process(void);
};

Adder::Adder(int a, int b) : op1(a), op2(b) { }

int Adder::process(void) 
{

	return op1 + op2;
}

class Calculator {
public:
	void run(void);
};

void Calculator::run(void) 
{
	cout << "두 개의 수를 입력하세요>>";
	int a, b;
	cin>>a>>b;
	Adder adder(a,b);
	cout << adder.process();

    return;
}

int main(void) 
{
	Calculator calc;
	calc.run();

    return 0;
}
#endif