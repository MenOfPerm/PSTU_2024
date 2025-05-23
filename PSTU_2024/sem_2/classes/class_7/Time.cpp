#include "Time.h"

Time::Time() : sec{ 0 }, min{ 0 } {}
Time::Time(int s, int m) : sec{ s }, min{ m } {}
Time::Time(const Time& obj) : sec{ obj.sec }, min{ obj.min } {}
Time& Time::operator=(const Time& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	
	sec = obj.sec;
	min = obj.min;

	return *this;
}
Time Time::operator*(const Time& obj)
{
	int total_sec = (min * 60 + sec) * (obj.min * 60 + obj.sec);
	return Time(total_sec % 60, total_sec / 60);
}
ostream& operator<<(ostream& out, const Time& obj)
{
	out << obj.min << ':' << obj.sec;
	return out;
}
istream& operator>>(istream& in, Time& obj)
{
	cout << "Enter minutes: ";
	in >> obj.min;
	cout << "Enter seconds: ";
	in >> obj.sec;
	return in;
}