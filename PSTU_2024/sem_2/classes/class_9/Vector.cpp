#include "Vector.h"
#include "Error.h"

Vector::Vector(int s)
{
	if(s > MAX_SIZE) throw MaxSizeError();
	if (s < 0) throw SizeError();
	if (s == 0) throw EmptyError();
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; ++i) { beg[i] = 0; }
}

Vector::Vector(int s, int* mas)
{
	if (s > MAX_SIZE) throw MaxSizeError();
	if (s < 0) throw SizeError();
	if (s == 0) throw EmptyError();
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; ++i) { beg[i] = mas[i]; }
}

Vector::Vector(const Vector& vec)
{
	size = vec.size;
	beg = new int[size];
	for (int i = 0; i < size; ++i) { beg[i] = vec.beg[i]; }
}

Vector::~Vector()
{
	if (beg != nullptr)
	{
		delete[] beg;
		beg = nullptr;
	}
}

const Vector& Vector::operator=(const Vector& v)
{
	if (this == &v) { return *this; }
	if (beg != nullptr) { delete[] beg; }
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; ++i) { beg[i] = v.beg[i]; }
	return *this;
}

int& Vector::operator[](int index)
{
	if (index < 0 || index >= size) throw IndexError();
	return beg[index];
}

Vector::operator int() { return size; }

const Vector& Vector::operator*(const Vector& vec)
{
	if (size != vec.size) throw DifferentSizeError();
	for (int i = 0; i < size; ++i)
	{
		beg[i] *= vec.beg[i];
	}
	return *this;
}

Vector Vector::operator+(int n)
{
	if (n < 0 || n >= size) throw IndexError();
	Vector vec(size - n);
	for (int i = 0; i < size - n; ++i)
	{
		vec.beg[i] = beg[i + n];
	}
	return vec;
}

ostream& operator<<(ostream& out, const Vector& vec)
{
	if (vec.size == 0) throw EmptyError();
	else
	{
		for (int i = 0; i < vec.size; ++i)
		{
			out << vec.beg[i] << ' ';
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Vector& vec)
{
	for (int i = 0; i < vec.size; ++i)
	{
		in >> vec.beg[i];
	}
	return in;
}