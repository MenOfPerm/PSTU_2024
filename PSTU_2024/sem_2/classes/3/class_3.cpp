//������� ����� Money ��� ������ � ��������� �������.
//����� ������ ���� ������������ ����� ������: ���� long ��� ������ � ���� int ��� ������.
//������� ����� ����� ��� ������ �� ����� ������ ���� �������� �� ����� ����� �������.
//�����������:
// �������� ����� � �������� �����
// �������� ��������� (>, <, ==).
#include <iostream>
using namespace std;
class money
{
	long rubl;
	int kopeica;

	public:
		// ������������
	money( long rub,int kop) 
	{
		rubl = rub;
		kopeica = kop;
	};

	money() { rubl = 0; kopeica = 0; };
	money(const money&a)
	{
		rubl = a.rubl;
		kopeica = a.kopeica;
	}
	// ����� ��� ��������� ���������� ���� � ���� ��� ������������ �������� � ������? �� �� ��������� ���������
	money& operator =(const money&);
	bool operator <(const money& a)
	{
		if (this->rubl * 100 + this->kopeica < a.rubl * 100 + a.kopeica) return true;
		else
		{
			return false;
		}
	};
	bool operator >(const money& a)
	{
		if ((this->rubl * 100 + this->kopeica) < (a.rubl * 100 + a.kopeica)) return false;
		else
		{
			return true;
		};
	};
	bool operator ==(const money& a) 
	{
		if ((this->rubl * 100 + this->kopeica) != (a.rubl * 100 + a.kopeica)) return false;
		else
		{
			return true;
		};
	};
	money& operator +(const money& a)
	{
		long long rub = this->rubl;
		long long rubplus = a.rubl;
		long long num = (rub * 100 + this->kopeica) + (rubplus * 100 + a.kopeica);
		this->rubl = num / 100;
		this->kopeica = num % 100;

	};
	friend ostream& operator << (ostream& out, const money& a);
	friend istream& operator >> (istream& in, money& a);
};

istream& operator >> (istream& in, money& a) 
{
	cout << "�����? "; in >> a.rubl;
	cout << "�������? "; in >> a.kopeica;
	return in;
};
ostream& operator << (ostream& out, const money& a)
{
	return (out << a.rubl << "," << a.kopeica);
};

money& money::operator = (const money& a) 
{
	if (this == &a)
	{
		return *this;
	}
	else
	{
		this->kopeica = a.kopeica;
		this->rubl = a.rubl;
	}

};

int main()
{
	setlocale(LC_ALL, "RU");
	money mon1(100, 20);
	money mon2(200, 90);
	money mo3 = mon2;
	cout << mo3 << endl;;
	bool e = mo3 == mo3;
	cout << e;
	e = mon1 < mon2;
	cout <<e ;

}
