//���� first � ������� ����� �, ���������� ����� , ���� second � ������� ����� y, ���������� �����.
// ����������� ����� distance() � ���������� ���������� �� ����� � ������������ (first, second)
// �� ������ ���������.
// ����� ������ �� ��������, ����� ����������� a^2+b^2 = c^2
// ������� :
// exit ��������� �������� ��������� � ����������� �����


#include <iostream>
using namespace std;
class myclass
{
	float x = 0;
	float y = 0;
public:
	void init(float a,float b) 
	{
		x = a;
		y = b;
	};
	// init ����� �� ����� �� � ��������� ������� ��� �������
	float calculate_distance();

	void read() 
	{
		cout << "������� ���������� �����" << endl;
		cout << "x: ";cin >> x;
		cout << "y";cin >> y;
		if ((x || y) == 0)
		{
			cout << "�� ��� ������ ���������, ��� ������ �������";
			exit;
		}
	};

};
float myclass::calculate_distance()
{
	float c = sqrt(x * x + y*y);
	if (x<0 or y<0)
	{
		return -(c);
	}
	else
	{
		return c;
	}

}

int main()
{
	setlocale(LC_ALL, "RU");
	myclass ee;
	ee.read();
	cout<<"���������� �� �����:"<<ee.calculate_distance();



}