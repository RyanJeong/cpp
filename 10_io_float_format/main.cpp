#include "../std_lib_facilities.h"

int main(void)
{
    try {
        // Floating-point formats(persist)
        //   defaultfloat is the default format
        // ------------------------------------
        // fixed        use fixed-point notation
        // scientific   use mantissa and exponent notation; the mantissa is always in the [1:10)
        //              range; that is, there is a single nonzero digit before the decimal point
        // defaultfloat choose fixed or scientific to give the numerically most accurate
        //              representation, within the precision of defaultfloat
        //
        // Floating-point precision(persist)
        //   defaultfloat format with precision 6 
        // ------------------------------------
        // fixed        precision is the number of digits after the decimal point
        // scientific   precision is the number of digits after the decimal point
        // defaultfloat precision is the total number of digits

        cout << 1234.56789 << '\t'
             << fixed << 1234.56789 << '\t'
             << scientific << 1234.56789 << '\n';
        cout << defaultfloat << setprecision(5)
             << 1234.56789 << '\t'
             << fixed << 1234.56789 << '\t'
             << scientific << 1234.56789 << '\n';
        cout << defaultfloat << setprecision(8)
             << 1234.56789 << '\t'
             << fixed << 1234.56789 << '\t'
             << scientific << 1234.56789 << '\n';

        return 0;
    }
    catch(exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Something terribad happened..\n";
        return 2;
    }
}
