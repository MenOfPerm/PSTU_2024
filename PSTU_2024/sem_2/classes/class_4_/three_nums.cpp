#include "thee_nums.h"
three_nums::three_nums(void) { first = 0; second = 0; thrird = 0; } 
//���������� 
three_nums::~three_nums(void) { } 
//����������� � ����������� 
three_nums::three_nums(int M,int C,int P) { first=M; second=C; thrird=P; } 
//����������� �����������
three_nums::three_nums(const three_nums& c) { first = c.first; second = c.second; thrird = c.thrird	; }
//������������
// 
 //���������� �������� ������������ 
three_nums& three_nums::operator = (const three_nums&c)
{ 
	if (&c==this) return *this; 
	first=c.first; 
	second=c.second; 
	thrird=c.thrird; 
	return *this; 
} 

//���������� ������� ��� ����� 
istream& operator>>(istream&in, three_nums&c)
{ 
	cout<<"\nfirst:";
	in>>c.first;
	cout<<"\nsecond:";
	in>>c.second;
	cout<<"\nthrird:";
	in>>c.thrird; 
	return in; 
} //���������� ������� ��� ������ 
ostream& operator<<(ostream&out,const three_nums&c)
{
	out << "\n you`r nums: ";
	out<<"\nFirst : "<<c.first;
	out<<"\nSecond : "<<c.second;
	out<<"\nThrird : "<<c.thrird;
	out<<"\n"; return out; 
}