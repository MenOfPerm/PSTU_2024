#pragma once

#include <iostream>

using namespace std;

class Time
{
private:
	int minutes;
	int seconds;
public:
	Time() : minutes{ 0 }, seconds{ 0 } {};
	Time(int m, int s) : minutes{ m }, seconds{ s } { normalize(); };
	Time(const Time& other) : minutes{ other.minutes }, seconds{ other.seconds } {};

	void normalize();

	int getMinutes() const { return minutes; }
	int getSeconds() const { return seconds; }

	void setMinutes(int m) { minutes = m; }
	void setSeconds(int s) { seconds = s; }

	Time& operator=(const Time& other);
	Time operator+(const Time& other) const;
	bool operator<(const Time& other) const;
	bool operator>(const Time& other) const;
	bool operator==(const Time& other) const;
	bool operator!=(const Time& other) const;

	friend ostream& operator<<(ostream& out, const Time& t);
	friend istream& operator>>(istream& in, Time& t);
};