// ����� �������� �� 6 ����������

#include <iostream>
#include <cstdarg>
using namespace std;

int nok	( int n, ...)
{
    int mass[6];
    int result = 0;
    int min;
    int temp;
    int delimoe = 1;// ������� ����� ������� (�*�*�...)
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; ++i) 
    {
        temp = va_arg(args, int);
        delimoe *= temp;
        mass[i] = temp;
    }
    va_end(args);
    // ���� ���
    min = abs(mass[0]);

    for (int e = 1; e < n; e++)// ������� ����������� ������� (��������� (-,+))
    {   
        int elem = abs(mass[e]);
        if (min > elem)
        {
            min = elem;
        }
    }

    int temp_of_elem=0;
    for (int i = 0; i < n; i++)//5
    {
        if (min <= 1) { return 0; }// ���� ��� �� ������ (�� ����� �� 0)
        if ((temp_of_elem == n) && (i == n))break;//���� ������ �������� ��� ���� ���������
        if (mass[i] % min == 0) { temp_of_elem++; }// ���� ������� ������� ������� �� �������������� ��� , ���������� ���
        else{temp_of_elem = 0; min--;i = -1;}// ���� �� �������� ��������� �������� � �������� ���� � ������
    }
    return (delimoe / min);

}

int  main()
{
    setlocale(LC_ALL, "RU");
    cout << "��������� ��������� ��� �� ������� (a*b*c...)/���" << endl << endl;;
    cout << "��� ���������� ���, ��������� �������: 0" << endl << endl;;
    cout <<"����� ��� ��� 3 ������ (10,50,100): " << nok(3, 10, 50, 100) << endl;
    cout <<"����� ��� ��� 5 ������ (10, 6, 30, 8, 80): " <<nok( 5, 10, 6, 30, 8, 80) << endl;
    cout <<"����� ��� ��� 6 ������ (9, 24, 17, 15, 19, 136): " << nok( 3, 9, 24, 17, 15, 19, 136) << endl;

}