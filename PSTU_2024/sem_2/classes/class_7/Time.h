#pragma once

#include <iostream>
using namespace std;

class Time
{
private:
	int sec;
	int min;
public:
	Time();
	Time(int s, int m);
	Time(const Time& obj);
	Time& operator=(const Time& obj);
	Time operator*(const Time& obj);
	friend ostream& operator<<(ostream& out, const Time& obj);
	friend istream& operator>>(istream& in, Time & obj);
};