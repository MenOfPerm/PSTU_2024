#include <iostream>
#include "PERSON.h"
#include "TEACHER.h"
#include "Vector.h"

using namespace std;

int main()
{
	Vector v(3);
	TEACHER T;
	cin >> T;
	PERSON* PT = &T;
	v.add(PT);
	cout << v;

	return 0;
}