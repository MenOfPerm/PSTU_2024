#include "Vector.h"
#include <iostream>

Vector::Vector(int n)
{
	beg = new PERSON* [n];
	cur = 0;
	size = n;
}
Vector::~Vector(void)
{
	if (beg != nullptr)  delete[]beg;
	beg = nullptr;
}
ostream& operator <<(ostream& out, const Vector& v)
{
	if (v.size == 0) { out << "Empty !" << endl; }
	PERSON** PP = v.beg;
	for (int i = 0; i < v.cur; ++i)
	{
		(*PP)->Show();
		PP++;
	}
	return out;
}
void Vector::add(PERSON* P)
{
	if (cur < size)
	{
		beg[cur] = P;
		++cur;
	}
}