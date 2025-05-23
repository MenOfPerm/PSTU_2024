#include "Money.h"

Money::Money() : rubles{ 0 }, kopecks{ 0 } {};
Money::Money(long rub, int kop) : rubles{ rub }, kopecks{ kop } { normalize(); }
Money::Money(const Money& m) : rubles{ m.rubles }, kopecks{ m.kopecks } {};
Money& Money::operator=(const Money& m)
{
	if (this == &m) { return *this; }
	rubles = m.rubles;
	kopecks = m.kopecks;
	return *this;
}

ostream& operator<<(ostream& out, const Money& m)
{
	out << m.rubles << ',' << (m.kopecks < 10 ? "0" : "") << m.kopecks;
	return out;
}
istream& operator>>(istream& in, Money& m)
{
	char comma;
	in >> m.rubles >> comma >> m.kopecks;
	m.normalize();
	return in;
}
fstream& operator<<(fstream& fout, const Money& m)
{
	fout << m.rubles << ',' << (m.kopecks < 10 ? "0" : "") << m.kopecks << '\n';
	return fout;
}
fstream& operator>>(fstream& fin, Money& m)
{
	char comma;
	fin >> m.rubles >> comma >> m.kopecks;
	m.normalize();
	return fin;
}

Money Money::operator+(const Money& m) const
{
	long totalRub = rubles + m.rubles;
	int totalKop = kopecks + m.kopecks;
	return Money(totalRub, totalKop);
}
Money Money::operator-(const Money& m) const
{
	return Money(rubles - m.rubles, kopecks - m.kopecks);
}
bool Money::operator==(const Money& m) const
{
	return ((rubles == m.rubles) && (kopecks == m.kopecks));
}

void Money::normalize()
{
	if (kopecks >= 100)
	{
		rubles += kopecks / 100;
		kopecks = kopecks % 100;
	}
}
void Money::increase()
{
	++rubles;
	kopecks += 50;
	normalize();
}
void Money::setRub(long rub) { rubles = rub; }
void Money::setKop(int kop) { kopecks = kop; }
long Money::getRub() const { return rubles; }
int Money::getKop() const { return kopecks; }