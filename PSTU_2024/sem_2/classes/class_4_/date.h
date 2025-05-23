#pragma once
#include "thee_nums.h"
class date :
    public three_nums
{

public :
    date(void);
    ~date(void);
    date(int,int,int,int);//конструктор с параметрами 
    date(const date & );//конструктор копирования 
    int Get_date(){return year,moth,day;}//модификатор 
    void Set_date(int,int,int); //селектор
    date& operator=(const date&); //операция присваивания 
    friend istream& operator>>(istream&in,date&l);//операция ввода 
    friend ostream& operator<<(ostream&out,const date&l); //операция вывода
protected:
    int year;
    int moth; 
    int day;

};

