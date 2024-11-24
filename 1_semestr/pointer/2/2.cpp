// Сложение двух целых чисел через указатели
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "rus");
	int num1, num2;
	cout << "введите два числа через enter" << endl;
	cin >> num1;
	cin >> num2;
	int* ptr1;
	int* ptr2;
	ptr1 = &num1;
	ptr2 = &num2;
	cout << *ptr1 + *ptr2 << endl;
	return 0;
}
