#include "header1.h"
#include "header2.h"

namespace header1 {
    int func(void)
    {
        header2::bar(); 

        return foo(); // header1::foo()
    }
}