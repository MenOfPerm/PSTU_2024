#include <iostream>
using namespace std;
int main()
{
	int first, b, c;
	cout << "enter count of numbers  ";
	cin >> c;
	cout << "enter numbers" << endl;
	cin >> first;
	int min = first;
	for (int i = 1; i < c; i++)
	{
		cin >> b;
		if (b > first)
		{
			first = b;
		}
		if (b < min)
		{
			min = b;
		}

	}
	cout << "min + max: " << first+min << endl;
	return 0;
}