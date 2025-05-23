
//������� �����: ������_����� (TRIAD) 
// ������_����� (first) - int 
// ������_����� (second) � int 
// ������_����� (third) - int 
// ���������� ������ ��������� ����� � ��������� ������. 
// ������� ����������� ����� DATE � ������ ���, ����� � �����.
// ���������� ������ ����� �������� ��������� ���.

#pragma once 
#include <string> 
#include <iostream> 
using namespace std;

class three_nums
{
public: three_nums(void); 
// destructor
public: ~three_nums(void);

 //���������� � ����������� 
 three_nums(int,int,int); 

 //����������� ����������� 
 three_nums(const three_nums&);

 //��������� 
int Get_first(){return first;} 
int Get_second(){return second;} 
int Get_thrird(){return thrird;} 

//������������  
void Set_first(int); 
void Set_second(int); 
void Set_thrird(int); 

//���������� �������� ������������ 
three_nums& operator=(const three_nums&);

//���������� ���������-������� �����-������
friend istream& operator>>(istream&in, three_nums&c);
friend ostream& operator<<(ostream&out,const three_nums&c);

protected: int first; int second; int thrird;
};

