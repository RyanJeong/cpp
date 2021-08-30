#include "header1.h"

using namespace header1;

int func(void)
{
    bar(); // header1::bar()

    return foo(); // header1:foo()
}