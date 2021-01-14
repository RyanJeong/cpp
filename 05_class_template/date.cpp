#include "../std_lib_facilities.h"
#include "date.h"

namespace Chrono {
  Month operator++(Month m)
  {
    //  You may use cast formats like `T(x)` only when `T` is a class type.
    //  int(x)   -> (int) x
    //  Month(m) <- (Month) m
    //
    //  Google C++ Style Guide
    m = (m == Month::kDec) ? Month::kJan : Month((int) m + 1);

    return m;
  }

  ostream &operator<<(ostream &os, const Month m)
  {

    return os << kMonthTbl[(int) m];
  }

  // Constructor
  Date::Date(long int dd) : days_{dd}
  {
    if (!IsDate(dd)) {
      throw Invalid{};
    }
  }

  int Date::GetDay() const
  {
    if (!cache_valid_) {
      UpdateCache();
    }

    return cache_.day_;
  }

  Month Date::GetMonth() const
  {
    if (!cache_valid_) {
      UpdateCache();
    }

    return cache_.month_;
  }

  int Date::GetYear() const
  {
    if (!cache_valid_) {
      UpdateCache();
    }

    return cache_.year_;
  }

  void Date::UpdateCache() const
  {
    int n{(int) days_ + 1};               // +1 to count Jan 1

    cache_.year_  = 1970;
    cache_.month_ = Month::kJan;

    // remove years
    int x;
    while ((x = IsLeapyear(cache_.year_) ? 366 : 365) && n > x) {
      n -= x;
      ++cache_.year_;
    }

    // remove months
    while ((x = DaysInMonth(cache_.year_, cache_.month_)) && n > x) {
      n -= x;
      ++cache_.month_;
    }

    cache_.day_  = n;
    cache_valid_ = true;

    return;
  }

  // modifying operations
  void Date::AddDay(int n)
  {
    // works for negativedays
    cache_valid_ = false;
    days_ += n;

    return;
  }

  void Date::AddMonth(int n)
  {
    // does not work for negative n
    if (!cache_valid_) {
      UpdateCache();
    }

    cache_valid_ = false;       // going to be modifying days
    days_ -= (cache_.day_ - 1); // set day to 1st of current month
    while (n > 0) {
      days_ += DaysInMonth(cache_.year_, cache_.month_);

      ++cache_.month_;
      if (cache_.month_ == Month::kJan) {
        ++cache_.year_;
      }
      --n;
    }
    days_ += (cache_.day_ - 1); // give back taken days

    return;
  }

  void Date::AddYear(int n)
  {
    if (!cache_valid_) {
      UpdateCache();
    }

    cache_valid_ = false;

    while (n > 0) {
      bool leap = (cache_.month_ > Month::kFeb)
          ? IsLeapyear(cache_.year_ + 1)
          : IsLeapyear(cache_.year_);

      days_ += leap ? 366 : 365;
      ++cache_.year_;

      --n;
    }

    return;
  }

  // helper functions
  bool IsDate(long int dd)
  {

    return (dd < 0) ? false : true;
  }

  bool IsLeapyear(int y)
  {

    return ((y % 4) == 0) ? true : false;
  }

  int DaysInMonth(int y, Month m)
  {
    switch (m) {
      case Month::kFeb:

        return IsLeapyear(y) ? 29 : 28;
      case Month::kApr:
      case Month::kJun:
      case Month::kSep:
      case Month::kNov:

        return 30;
      default:

        return 31;
    }
  }

  bool operator==(const Date &a, const Date &b)
  {

    return a.GetDays() == b.GetDays();
  }

  bool operator!=(const Date &a, const Date &b)
  {

    return !(a == b);
  }

  ostream &operator<<(ostream &os, const Date &d)
  {

    return os << '(' 
              << d.GetYear() << ", "
              << d.GetMonth() << ", "
              << d.GetDay() 
              << ')';
  }

  istream &operator>>(istream &is, Date &dd)
  {
    // need to burn a day since 'days' is the number of days since Jan 1,
    // 1970. (Jan 1 is not counted)

    int  y, m, d;
    char ch1, ch2, ch3, ch4;

    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) {

      return is;
    }
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
      is.clear(std::ios_base::failbit);           // set the fail bit

      return is;
    }

    long int days{-1};                             // burnt day

    for (int i = 1970; i < y; ++i) {
      days += IsLeapyear(i) ? 366 : 365;
    }
    for (int i = 1; i < m; ++i) {
      days += DaysInMonth(y, Month(i));
    }
    days += d;
    dd   = Date{days};

    return is;
  }
}
