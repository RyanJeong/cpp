#include "../std_lib_facilities.h"

int main(void)
{
    try {
        cout << "Please enter some integers. Feel free to mix it up:\n";

        while (cin) {
            string input;

            cin >> input;
            stringstream ss{input};
            ss.unsetf(ios::dec); // don’t assume decimal (so that 0x can mean hex)

            int value;
            ss >> value;

            // oct, hex, dec(for decimal), showbase, and noshowbase persist 
            // (“stick,” “are sticky”)
            // 
            // the field(setw) width “doesn’t stick.”
            cout << setw(12) << showbase;   

            if (input[0] == '0') {
                if (input[1] == 'x' || input[1] == 'X') {
                    cout << hex << value << " hexadecimal\t";
                } else {
                    cout << oct << value << " octal\t\t";
                }
            } else {
                cout << dec << value << " decimal\t\t";
            }

            cout << "converts to\t"
                 << dec << value << " decimal\n";
        }

        return 0;
    } catch(exception& e) {
        cerr << e.what() << '\n';

        return 1;
    } catch(...) {
        cerr << "Something bad happened..\n";

        return 2;
    }
}
