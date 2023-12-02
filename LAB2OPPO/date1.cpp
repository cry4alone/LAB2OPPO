#include "date1.h"



void date1::set_Date(std::istream& ist)
{
    read_file(ist);
    check_file(ist);
}
void date1::print_Date() const
{
    std::cout << year << " " << month << " " << day << " ";
}

void date1::read_file(std::istream& ist)
{
    char dot;
    ist >> year;
    dot = ist.get();
    if (dot != '.') { throw std::runtime_error("Expected dot"); }
    ist >> month;
    dot = ist.get();
    if (dot != '.') { throw std::runtime_error("Expected dot"); }
    ist >> day;
    //if (!ist.good()) { throw std::runtime_error("string fail"); }
}

void date1::check_file(std::istream& ist)
{
    static const std::vector<int>days_of_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    static const std::vector<int>days_of_month_v = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (check_year(year))
    {
        if (days_of_month_v[month - 1] <= day) { throw std::runtime_error("Wrong day"); }
    }
    else
    {
        if (days_of_month[month - 1] <= day) { throw std::runtime_error("Wrong day"); }
    }
    if (!((0 < month) && (month < 13))) { throw std::runtime_error("Wrong month"); }
}

bool date1::check_year(int year)
{
    if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
    {
        return true;
    }
    return false;
}