#include <iostream>
using namespace std;

int main ()
{
	setlocale(LC_CTYPE, "rus");
	int num1, num2;
	int* ptr1;
	int* ptr2;
	int* ptr3;
	cout << "������� ��� ����� ����� enter" << endl;
	cin >> num1;
	cin >> num2;


	ptr1 = &num1;
	ptr2 = &num2;

	ptr3 = ptr2;
	ptr2 = ptr1;
	ptr1 = ptr3;
	cout << "������ ��������� : " << *ptr1 << " ������ ��������� : " << *ptr2 << endl;
	return 0 ;
}
