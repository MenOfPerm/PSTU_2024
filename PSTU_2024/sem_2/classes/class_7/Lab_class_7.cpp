#include "Vector.h"
#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
	Time t;
	cin >> t;
	cout << t << endl;
	Vector<Time>A(5, t);
	cin >> A;
	cout << A << endl;
	Vector <Time>B(10, t);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "size=" << A() << endl;

	return 0;
}