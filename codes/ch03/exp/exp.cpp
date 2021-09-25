#include "exp.h"

int Exp::getValue(void) 
{
	int res = 1;

	for (int i = 0; i<exp; i++) {
		res=res*base;
    }

	return res;
}

bool Exp::equals(Exp b) 
{
	if (getValue()==b.getValue()) {

		return true;
    }

    return false;
}