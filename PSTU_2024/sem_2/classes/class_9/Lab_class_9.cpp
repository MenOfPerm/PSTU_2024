#include <iostream>
#include "Vector.h"
#include "Error.h"

using namespace std;

int main()
{
	try
	{
		Vector v1(5);
		for (int i = 0; i < 5; ++i) { v1[i] = 1 + i; }

		Vector v2(10);
		for (int i = 0; i < 10; ++i) { v2[i] = 1 + i; }

		Vector v3 = v1 * v2;
	}
	catch (Error& e)
	{
		e.what();
	}

	return 0;
}