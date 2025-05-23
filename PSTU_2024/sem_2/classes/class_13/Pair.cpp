#include "Pair.h"

bool Pair::operator<(const Pair& pair) const
{
	return (static_cast<double>(first + second) < static_cast<double>(pair.first + pair.second));
}

bool Pair::operator>(const Pair& pair) const
{
	return (static_cast<double>(first + second) > static_cast<double>(pair.first + pair.second));
}

Pair Pair::operator+(const Pair& pair) const
{
	return Pair(first + pair.first, second + pair.second);
}

Pair Pair::operator/(size_t size) const
{
	return Pair(first / size, second / size);
}

Pair Pair::operator/(const Pair& pair) const
{
	return Pair(first / pair.first, second / pair.second);
}

ostream& operator<<(ostream& out, const Pair& pair)
{
	out << '(' << pair.first << " : " << pair.second << ')';
	return out;
}

istream& operator>>(istream& in, Pair& pair)
{
	cout << "Enter pair first: "; in >> pair.first;
	cout << "Enter pair second: "; in >> pair.second;
	return in;
}