#pragma once
#include <fstream>
#include <iostream>
#include <array>
#include <string>
class date1 {
public:
    int day;
    int month;
    int year;
    void set_Date(std::istream& ist);
    void print_Date() const;
    void read_file(std::istream& ist);
    void check_file(std::istream& ist);
    static bool check_year(int year);
};

namespace vec {
    constexpr std::array<int, 12> days_of_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    constexpr std::array<int, 12> days_of_month_v = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}


