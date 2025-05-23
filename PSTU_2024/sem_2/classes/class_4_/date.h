#pragma once
#include "thee_nums.h"
class date :
    public three_nums
{

public :
    date(void);
    ~date(void);
    date(int,int,int,int);//����������� � ����������� 
    date(const date & );//����������� ����������� 
    int Get_date(){return year,moth,day;}//����������� 
    void Set_date(int,int,int); //��������
    date& operator=(const date&); //�������� ������������ 
    friend istream& operator>>(istream&in,date&l);//�������� ����� 
    friend ostream& operator<<(ostream&out,const date&l); //�������� ������
protected:
    int year;
    int moth; 
    int day;

};

