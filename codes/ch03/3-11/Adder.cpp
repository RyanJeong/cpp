#include "adder.h"

Adder::Adder(int a, int b) : op1(a), op2(b) { }

// inline int Adder::process(void)  compile-time
int Adder::process(void) 
{

	return op1 + op2;
}