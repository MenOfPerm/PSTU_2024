
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int num1, num2, num3, max;
    cout << "������� 3 ����� ����� ��� ��������� ����� enter" << endl;
    cin >> num1 >> num2 >> num3;
    if (num1 >= num2) { max = num1; }
    else { max = num2; }
    if (max < num3) { max = num3; }
    cout << "������������ �����: " << max << endl;
    return 0;
}
