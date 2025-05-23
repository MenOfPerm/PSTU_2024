#include <iostream>
#include "file_work.h"
#include "Money.h"

using namespace std;

int main()
{
	make_file("test.txt");
	print_file("test.txt");
	int n = add_file("test.txt", 3, 1);
	print_file("test.txt");
	cout << n;

	return 0;
}