#include "../std_lib_facilities.h"
#include "date.h"

using Chrono::Date;

int main(void)
{
  try {
    Date d1{0};

    cout << d1 << '\n';

    Date d2{1};

    cout << d2 << '\n';

    Date d3{365};

    cout << d3 << '\n';

    Date d4{1096}; // Day 0 + 365 + 365 + 366 (1972 was leapyear)

    cout << d4 << '\n'; //> (1973, January, 1)

    Date d5{3344};

    cout << d5 << '\n'; //> (1979, February, 27)

    Date d6 {};

    cout << "Enter a day in the format (YYYY, MM, DD):\n";
    cin >> d6;
    cout << d6 << ": " << d6.GetDays() << '\n';

    return 0;
  } catch(exception &e) {
    cerr << "Exception: " << e.what() << '\n';

    return 1;
  } catch(...) {
    cerr << "Unknown exception\n";

    return 2;
  }
}
