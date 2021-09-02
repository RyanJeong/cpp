#include <iostream>

class Date {
public:
    void set_date(int y, int m, int d);
    void add_day(int num);
    void add_month(int num);
    void add_year(int num);
    void view_date(void);
private:
    int year_;
    int month_;
    int day_;
};

void Date::set_date(int y, int m, int d)
{
    if (y<0 || m<0 || d<0) {
        year_=0;
        month_=0;
        day_=0;
    }
    else {
        year_=y;
        month_=m;
        day_=d;
    }

    return;
}

void Date::add_day(int num)
    {
    const char daytab_[2][13] = { 
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
    return;
}

void Date::add_month(int num)
{
    if (num<0) {

        return;
    }
    year_+=num/12;
    month_+=num%12;
    if (month_>12) {
        ++year_;
        month_-=12;
    }

    return;
}

void Date::add_year(int num)
{
    if (num<0) {

        return;
    }
    year_+=num;

    return;
}

void Date::view_date(void)
{
    std::cout << "Year: " << year_ 
              << ", Month: " << month_ 
              << ", Day: " << day_ << std::endl;

    return;
}

int main(void)
{
    Date date;

    date.set_date(2012,2,28);
    date.view_date();
    date.add_year(2);
    date.view_date();
    date.add_month(13);
    date.view_date();
    date.add_month(11);
    date.view_date();

    return 0;
}