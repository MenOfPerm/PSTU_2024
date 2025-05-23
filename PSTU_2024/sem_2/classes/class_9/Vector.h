#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

class Vector
{
private:
	int size;
	int* beg;
public:
	Vector() : size{ 0 }, beg{ nullptr } {};
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector&);
	~Vector();

	const Vector& operator=(const Vector& v);
	int& operator[](int i);
	operator int();
	const Vector& operator*(const Vector&);
	Vector operator+(int n);

	friend ostream& operator<<(ostream& out, const Vector&);
	friend istream& operator>>(istream& in, Vector&);
};