#include "../std_lib_facilities.h"
#include "const.h"
#include "token.h"
#include "variable.h"
#include "util.h"

extern SymbolTable st;

int main(void)
{
    try {
        st.defineName("pi", kPi, true);
        st.defineName("e", kE, true);      

        TokenStream ts{cin};

        cout << "Simple Calculator (type ? for help)\n";
        Calculate(ts);

        return 0;
    } catch(exception &e) {
        cerr << "Exception: " << e.what() << '\n';
        return 1;
    } catch(...) {
        cerr << "Unknown exception\n";
        return 2;
    }
}
