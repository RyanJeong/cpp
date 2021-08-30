#include "../std_lib_facilities.h"

enum class Month {
    kJan=1, kFeb, kMar, kApr, kMay, kJun, kJul, kAug, kSep, kOct, kNov, kDec
};

vector<string> month_tbl = { 
    "January", "February", "March", "April",
    "May", "June", "July", "August", 
    "September", "October", "November", "December" 
};

// Don't go out of your way to avoid defining operator overloads. 
// For example, prefer to define ==, =, and <<, rather than Equals(), CopyFrom(), and PrintTo().
//
// Google C++ Style Guide
ostream &operator<<(ostream &os, Month m)
{

    return os << month_tbl[int(m)];
}

class Date {
public:
    // constructor
    Date(int, Month, int);

    void  addDay(int n);
    int   GetYear() const { return y_; }
    Month GetMonth() const { return m_; }
    int   GetDay() const { return d_; }
private:
    int   y_;
    Month m_;
    int   d_;
};

// constructor
Date::Date(int yy, Month mm, int dd)
    :y_{yy}, m_{mm}, d_{dd}
{
    if (d_ < 1 || 31 < d_) {
        error("impossible day");
    }
}

void Date::addDay(int n)
{
    d_ += n;
    if (d_ > 31) {
        d_ %= 31;
    }

    return;
}

ostream &operator<<(ostream &os, const Date &d)
{

    return os << '(' << d.GetYear()
              << ',' << d.GetMonth()
              << ',' << d.GetDay() << ')';
}

int main(void)
{
    try {
        Date today{1978, Month::kJun, 25};
        Date tomorrow{today};
        tomorrow.addDay(1);

        cout << today << '\n'
             << tomorrow << '\n';

        // Date bad_day(2004, 13, -5);

        return 0;
    } catch(exception& e) {
        cerr << e.what() << '\n';

        return 1;
    } catch(...) {
        cerr << "unknown error" << '\n';

        return 2;
    }
}
