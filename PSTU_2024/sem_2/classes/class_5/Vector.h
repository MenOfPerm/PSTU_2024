#pragma once
#include "TEACHER.h"

class Vector
{
private:
	int size = 0;
	int cur = 0;
	PERSON** beg = nullptr;
public:
	Vector(void) : size{ 0 }, cur{ 0 }, beg{ nullptr } {};
	Vector(int);
	~Vector(void);
	friend ostream& operator <<(ostream& out, const Vector&);
	void add(PERSON*);
};