#include <iostream>

#include "calculator.h"
#include "adder.h"

using namespace std;

void Calculator::run(void) 
{
	cout << "두 개의 수를 입력하세요>>";
	int a, b;
	cin>>a>>b;
	Adder adder(a,b);
	cout << adder.process();

	return;
}