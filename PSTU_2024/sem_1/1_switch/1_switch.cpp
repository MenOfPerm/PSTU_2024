#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int id_oper;
    float num_1, num_2, answer;
    cout << "������� ����� �������� (1 = +,2 = -,3 = *,4 = /)" << endl;
    cin >> id_oper;
    cout << "������� ��� ����� � �������� ��������, ����� ENTER" << endl;
    cin >> num_1 >> num_2;
    switch (id_oper)
    {
    case 1:answer = num_1 + num_2; break;
    case 2:answer = num_1 - num_2; break;
    case 3:answer = num_1 * num_2; break;
    case 4:answer = num_1 / num_2; break;
    default: cout << "������ ����� ������� ������ ����� �����, �� 1 �� 4 (������������)" << endl; return 1;
    }
    cout << "��������� ����������: "<< answer << endl; //� ���� ������������� answer � ������, ����� ���?
    return 1;
}