//��� ������� ����� ����� ����� ���� ����
// ��� ������ ����� ������ ������ �������� �����
//7.18

#include <iostream>
#include<string>
using namespace std;



int trash(int a[7]) 
{
	int maxx = a[0];
	for (int i = 1; i < 6; i++)
	{
		if (a[i] > maxx) maxx = a[i];

	}
	return maxx;
}

int trash(string str)
{
	int len = 0;
	int len_temp = 0;
	for (int i = 0; i < str.length() - 1; i++)
	{
		while ((str[i] != ' '))
		{
			if (i== str.length() - 1)
			{
				break;
			}
			len_temp++;
			i++;
		}
		if (len_temp > len)len = len_temp;
		len_temp = 0;
	}
	return len;
}


int main()
{	

	setlocale(LC_ALL, "RU");
	int a[7] = {123,123,345,568345,6990,-1235,346};
	string b = "������� �����, ����� � ���������������������������.";
	cout << "��������� ���������� ������: \n\"" << b <<'\"' << endl;
	cout << "� ������������� ������: " << "123,123,345,568345,6990,-1235,346" << endl << endl;
	cout <<"������������ ������� �������: "<< trash(a) << endl;
	cout <<"������ ������ �������� �����: "<< trash(b) << endl;




}