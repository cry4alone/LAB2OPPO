#pragma once
#include <fstream>
#include <iostream>
#include <vector>
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


