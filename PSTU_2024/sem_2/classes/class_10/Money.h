#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Money
{
private:
	long rubles;
	int kopecks;
	void normalize();
public:
	Money();
	Money(long rubles, int kopecks);
	Money(const Money&);
	Money& operator=(const Money&);
	~Money() = default;

	friend ostream& operator<<(ostream& out, const Money&);
	friend istream& operator>>(istream& in, Money&);
	friend fstream& operator<<(fstream& fout, const Money&);
	friend fstream& operator>>(fstream& fin, Money&);

	Money operator+(const Money&) const;
	Money operator-(const Money&) const;
	bool operator==(const Money&) const;

	void increase();
	void setRub(long rub);
	void setKop(int kop);
	long getRub() const;
	int getKop() const;
};