#include "date.h" 
//����������� ��� ���������� 
date::date(void):three_nums() { year = 0, moth = 0, day = 0; }
//��������� 
date::~date(void) { } 
//����������� � ����������� 
date::date(int M, int C, int P, int G):three_nums(M,C,P) { year=G; }
//����������� ����������� 
date::date(const date &L) 
{ 
	first=L.first;
	second=L.second;
	thrird=L.thrird; 
	year = L.year;
	moth = L.moth;
	day = L.day;
}
//����������� 
void date::Set_date(int y, int m, int d) { year = y, moth = m, day = d; }
//������� ������������ 
date& date::operator=(const date&l) 
{ 
	if(&l==this)return *this;
	first=l.first; 
	second=l.second; 
	thrird=l.thrird; 
	year=l.year;
	moth = l.moth;
	day = l.day;

	return *this; } 
//�������� ����� 
istream& operator>>(istream&in,date&l) 
{
	cout << "\nfirst:";
	in >> l.first;
	cout << "\nsecond:";
	in >> l.second;
	cout << "\nthrird:";
	in >> l.thrird;

	cout << "\nyear:";
	in >> l.year;
	cout << "\nmonth:";
	in >> l.moth;
	cout << "\nday:";
	in >> l.day;
	return in;
} 
//�������� ������ 
ostream& operator<<(ostream& out, const date& l)
{
	out << "\n you`r nums: ";
	out << "\nFirst : " << l.first;
	out << "\nSecond : " << l.second;
	out << "\nThrird : " << l.thrird;
	out << "\n"; 
	out << "\n you`r date: ";
	out << "\nyear : " << l.year;
	out << "\nmonth : " << l.moth;
	out << "\nday : " << l.day;
	out << "\n";
	return out;


}