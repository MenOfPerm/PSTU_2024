//���������������� ����� �������� 
// ����� � string 
//������� � double
//���������� ������ � int

#include <iostream>
using namespace std;
class apartment
{
	string adress;
	double S;
	int numberOfRooms;

public:
	//������������
	apartment() 
	{
		this->adress = "����������� ��������";
		this->S = 100;
		this->numberOfRooms = 999;
	};

	apartment(string adr, double pl, int rooms)
	{
		adress = adr;
		S = pl;
		numberOfRooms = rooms;

	};

	apartment(const apartment&a)
	{
		adress = a.adress;
		S = a.S;
		numberOfRooms = a.numberOfRooms;
	}
	void info()
	{

		cout << "��� �������� �� ������: " << adress << endl;
		cout << "� �������� :" << S << endl;
		cout << "� ����������� ������: " << numberOfRooms << endl << endl;
	
	}
	void change_adress(string new_adress)
	{
		adress = new_adress;
	}
	//--------------------------------------
	// ���������� (����� �� ������ ���� � ������ ��� ������������ �������� ������ , �� ���������� � ���� �� � ���)
	//~apartment() {};

};

int main()
{
	setlocale(LC_ALL, "RU");
	apartment e ;// ������ ����� ������
	string adr = "����� �����";
	double s = 123;
	int rooms = 5;
	apartment x(adr, s, rooms);
	apartment y(x); // ��� y = x
	// Person* pp1=new(Person);
	//��������� �� ������ ������ 
	//Person*pp2=new Person(�Petrov�,32);
	//��������� �� ������
	y.info();
	x.info();
	e.info();

}