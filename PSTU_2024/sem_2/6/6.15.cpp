// ������� ����� � ������� ��� ��������� �����+�����
#include <iostream>
#include<string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");
	string str;
	cout << "������� ���� ������"<<endl;
	getline(cin, str);
	int first;
	cout << str.length() << endl;
	for (int i = 0; i < str.length()-2; i++)// ���������� ��������
	{
		if (str[i]!=' ')
		{
			cout << i << endl;
			first = i;
			bool flag_digit = false;// ���� �� ������� ����� � �����
			bool flag_isletter = false;//���� �� ������� ����� � �����
			while (str[i]!=' ')//�������� ������ �� �����
			{
				if (str[i] == '.')break;
				if (isdigit(str[i]))flag_digit = true;
				if (!isdigit(str[i]))flag_isletter = true;
				i++;
			}
			if (flag_digit && flag_isletter){}// ��������� ������� 
			else//
			{
				str.erase(first, i-first+1);
				i = first;
			}
		}
	}

	str.insert(first, ".");//
	cout << str << endl;


}

