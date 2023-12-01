#pragma once
#include<iostream>
class Time1
{
public:
	int min;
	int hour;
	void set_time(std::istream& ist);
	void check_time();
};


