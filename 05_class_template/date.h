#ifndef __DATE_H__
#define __DATE_H__

#include "../std_lib_facilities.h"

namespace Chrono {
  enum class Month {
    kJan=1, kFeb, kMar, kApr, kMay, kJun, kJul, kAug, kSep, kOct, kNov, kDec
  };

  const vector<string> kMonthTbl = { "unused", // burn 0 index
    "January", "February", "March", "April",
    "May", "June", "July", "August", 
    "September", "October", "November", "December" 
  };

  Month   operator++(Month m);
  ostream &operator<<(ostream &os, const Month m);

  enum class Day {
    kSun, kMon, kTue, kWed, kThu, kFri, kSat
  };

  struct DateRep {
    int   year_  = 1970;
    Month month_ = Month::kJan;
    int   day_   = 1;
  };

  class Date {
  public:
    class Invalid { }; // to throw as exception

    Date(long int);       // check for valid date and initialize
    Date() : days_{0} { } // default constructor

    // Class functions can have the const qualifier to indicate the function 
    // does not change the state of the class member variables 
    // (e.g., class Foo { int Bar(char c) const; };).
    //
    // Google C++ Style Guide
    // non-modifying operations:
    int      GetDay() const;
    Month    GetMonth() const;
    int      GetYear() const;
    void     UpdateCache() const;

    long int GetDays() const { return days_; }

    // modifying operations (invalidate cache):
    void AddDay(int n);
    void AddMonth(int n);
    void AddYear(int n);
  private:
    long int        days_;
    mutable bool    cache_valid_ = false;
    mutable DateRep cache_;
  };

  bool IsDate(long int);  // true for valid date
  bool IsLeapyear(int y); // true if y is a leap year
  int  DaysInMonth(int y, Month m);

  bool operator==(const Date &a, const Date &b);
  bool operator!=(const Date &a, const Date &b);

  ostream &operator<<(ostream &os, const Date &d);
  istream &operator>>(istream &is, Date &d);
}
#endif
