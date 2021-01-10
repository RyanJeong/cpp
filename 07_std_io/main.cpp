#include "../std_lib_facilities.h"

constexpr int kNotAReading = -7777;
constexpr int kNotAMonth = -1;
constexpr int kImplausibleMin = -200;
constexpr int kImplausibleMax = 200;

void endOfLoop(istream &ist, char term, const string &message)
{
  // must add ist.exception for if ist goes 'bad'
  if (ist.fail()) { // use term as terminator and/or separator
    ist.clear();

    char ch;
    if (ist >> ch && ch==term) {

      return; // all is fine
    }
    error(message);
  }
}

// A struct is a class where members are public by default:
struct Day {
  vector<double> hour_{vector<double>(24, kNotAReading)};
};

// a month of temperature readings
struct Month {
  int         month_{kNotAMonth}; // [0:11] January is 0
  vector<Day> day_{32};           // [1:31] one vector of readings per day
};

// a year of temperature readings, organized by month
struct Year {
  int           year_;      // positive == A.D.
  vector<Month> month_{12}; // [0:11] January is 0
};

struct Reading {
  int    day_;
  int    hour_;
  double temperature_;
};


bool isValid(const Reading &r)
{
  // a rough test
  if (r.day_ < 1 || 31 < r.day_) {

    return false;
  }
  if (r.hour_ < 0 || 23 < r.hour_) {

    return false;
  }
  if (r.temperature_ < kImplausibleMin || kImplausibleMax < r.temperature_) {

    return false;
  }

  return true;
}

istream &operator>>(istream &is, Reading &r)
{
  // read a temperature reading from is into r
  // format: ( 3 4 9.7 )
  // check format but don't bother with data validity
  char ch1;

  if (is >> ch1 && ch1 != '(') {
      is.unget();
      is.clear(ios_base::failbit);

      return is;
  }

  char   ch2;
  int    d;
  int    h;
  double t;

  is >> d >> h >> t >> ch2;
  if (!is || ch2 != ')') {
    error("bad reading");
  }
  r.day_         = d;
  r.hour_        = h;
  r.temperature_ = t;

  return is;
}

vector<string> month_input_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun",
    "jul", "aug", "sep", "oct", "nov", "dec"
};

int MonthToInt(string s)
{
  // is s the name of a month? If so return its index [0:11] otherwise -1
  for (int i = 0; i < 12; ++i) {
    if (month_input_tbl[i] == s) {

      return i;
    }
  }

  return -1;
}

vector<string> month_print_tbl = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

string intToMonth(int i)
{
  // months [0:11]
  if (i < 0 || 12 <= i) {
    error("bad month index");
  }

  return month_print_tbl[i];
}

istream &operator>>(istream &is, Month &m)
{
  // read a month from is into m
  // format: { month feb ... }
  char ch{0};

  if (is >> ch && ch != '{') {
    is.unget();
    is.clear(ios_base::failbit);

    return is;
  }

  string month_marker;
  string mm;

  is >> month_marker >> mm;
  if (!is || month_marker != "month") {
    error("bad start of month");
  }
  m.month_ = MonthToInt(mm);

  int duplicates{0};
  int invalids{0};

  for (Reading r; is >> r; ) {
    if (isValid(r)) {
      if (m.day_[r.day_].hour_[r.hour_] != kNotAReading) {
        ++duplicates;
      }
      m.day_[r.day_].hour_[r.hour_] = r.temperature_;
    } else {
      ++invalids;
    }
  }
  if (invalids) {
    error("invalid readings in month", invalids);
  }
  if (duplicates) {
    error("duplicate readings in month", duplicates);
  }
  endOfLoop(is, '}', "bad end of month");

  return is;
}

istream &operator>>(istream &is, Year &y)
{
  // read a year from is into y
  // format: { year 1972 ... }
  char ch;

  is >> ch;
  if (ch != '{') {
    is.unget();
    is.clear(ios::failbit);

    return is;
  }

  string year_marker;
  int    yy;

  is >> year_marker >> yy;
  if (!is || year_marker != "year") {
    error("bad start of year");
  }
  y.year_ = yy;

  while (true) {
    Month m; // get a clean m each time around

    if (!(is >> m)) {
      break;
    }
    y.month_[m.month_] = m;
  }
  endOfLoop(is, '}', "bad end of year");

  return is;
}

void PrintYear(ofstream &ofs, Year y)
{
  // write year data to destination output stream
  ofs << y.year_ << ":\n";
  for (Month m : y.month_) {
    if (m.month_ != kNotAMonth) {
      ofs << '\t' << intToMonth(m.month_) << '\n';
      for (int d = 1; d < (int) m.day_.size(); ++d) {
        for (int h = 0; h < (int) m.day_[d].hour_.size(); ++h) {
          if (m.day_[d].hour_[h] != kNotAReading) {
            ofs << "\t\t" << d << '\t' << h << '\t'
                << m.day_[d].hour_[h] << '\n';
          }
        }
      }
    }
  }

  return;
}

int main(void)
{
  try {
    // open an input file:
    cout << "Please enter input file name\n";
    string iname;
    cin >> iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file", iname);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);  // throw for bad()

    // open an output file
    cout << "Please enter output file name\n";
    string oname;
    cin >> oname;
    ofstream ofs {oname};
    if (!ofs) error("can't open output file", oname);

    // read an arbitrary number of years:
    vector<Year> ys;
    while (true) {
      Year y;         // get a freshly initialized Year each time around
      if (!(ifs >> y)) break;
      ys.push_back(y);
    }
    cout << "read " << ys.size() << " years of readings\n";

    for (Year& y : ys) PrintYear(ofs, y);

    return 0;
  }
  catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';

    return 1;
  }
  catch (...) {
    cerr << "Error: Something strange happened..\n";

    return 2;
  }
}
