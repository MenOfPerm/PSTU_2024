#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "rus");
	float num,end;
	cout << "������� �����:" << endl;
	cin >> num;
	if (num < 5) { end = num * 3; }
	if (num > 7) { end = num + 3; }
	else { end = num / 10; }
	cout << "���������: " << end << endl;
}
