#include "Time.h"

void Time::normalize()
{
	if (seconds >= 60)
	{
		minutes += seconds / 60;
		seconds %= 60;
	}
}

Time& Time::operator=(const Time& other)
{
	if (this == &other) return *this;
	minutes = other.minutes;
	seconds = other.seconds;
	return *this;
}

Time Time::operator+(const Time& other) const
{
	return Time(minutes + other.minutes, seconds + other.seconds);
}

bool Time::operator<(const Time& other) const
{
	return (minutes * 60 + seconds < other.minutes * 60 + other.seconds);
}

bool Time::operator>(const Time& other) const
{
	return (minutes * 60 + seconds > other.minutes * 60 + other.seconds);
}

bool Time::operator==(const Time& other) const
{
	return (minutes * 60 + seconds == other.minutes * 60 + other.seconds);
}

bool Time::operator!=(const Time& other) const
{
	return (minutes * 60 + seconds != other.minutes * 60 + other.seconds);
}

ostream& operator<<(ostream& out, const Time& t)
{
	out << '(' << t.minutes << ':' << (t.seconds < 10 ? "0" : "") << t.seconds << ')';
	return out;
}

istream& operator>>(istream& in, Time& t)
{
	char colon;
	in >> t.minutes >> colon >> t.seconds;
	t.normalize();
	return in;
}