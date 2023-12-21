// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Time1.h"
#include <iostream>

void Time1::set_time(std::istream& ist)
{
	ist >> hour;
	char doubledot = ':';
	if (doubledot != ist.get()) { throw std::runtime_error("Expected double dot"); }
	ist >> min;
	if (ist.fail()) { throw std::runtime_error("stream fail"); }
	check_time();
}

void Time1::check_time()
{
	if (!((-1 < hour) && (hour < 25))) { throw std::runtime_error("Wrong hour"); }
	if (!((-1 < min) && (min < 60))) { throw std::runtime_error("Wrong minute"); }
}
