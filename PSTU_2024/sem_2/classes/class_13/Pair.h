#pragma once

#include <iostream>

using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair() : first(0), second(0.0) {}
	Pair(int first, double second) : first(first), second(second) {};
	Pair(const Pair& p) : first(p.first), second(p.second) {};
	~Pair() {}
	
	int get_first() const { return first; }
	int get_second() const { return second; }
	void set_first(int f) { first = f; }
	void set_second(int s) { second = s; }

	bool operator<(const Pair& pair) const;
	bool operator>(const Pair& pair) const;
	Pair operator+(const Pair& pair) const;
	Pair operator/(size_t size) const;
	Pair operator/(const Pair& pair) const;

	friend ostream& operator<<(ostream& out, const Pair& pair);
	friend istream& operator>>(istream& in, Pair& pair);
};