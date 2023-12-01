#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include "date1.h"
#include "time1.h"
class Zan
{
private:
    std::string name;
    date1 currdate;
    Time1 currtime;
public:
    void load_txt(std::istream& ist);
    void print_txt(std::ostream& ost);
    void check_name();
};


