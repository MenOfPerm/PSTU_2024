#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    float num1, num2;
    cout << "������� ��� ����� ����� enter" << endl;
    cin >> num1 >> num2;
    if (num2 == 0) { cout << "� ��� �� ����������� ��� �� 0 ������?" << endl; }
    else { cout << "��������� �������: " << num1 / num2 << endl; }
}