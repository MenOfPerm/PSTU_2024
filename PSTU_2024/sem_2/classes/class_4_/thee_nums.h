
//Базовый класс: ТРОЙКА_ЧИСЕЛ (TRIAD) 
// Первое_число (first) - int 
// Второе_число (second) – int 
// Третье_число (third) - int 
// Определить методы изменения полей и сравнения триады. 
// Создать производный класс DATE с полями год, месяц и число.
// Определить полный набор операций сравнения дат.

#pragma once 
#include <string> 
#include <iostream> 
using namespace std;

class three_nums
{
public: three_nums(void); 
// destructor
public: ~three_nums(void);

 //констрктор с параметрами 
 three_nums(int,int,int); 

 //конструктор копирования 
 three_nums(const three_nums&);

 //селекторы 
int Get_first(){return first;} 
int Get_second(){return second;} 
int Get_thrird(){return thrird;} 

//модификаторы  
void Set_first(int); 
void Set_second(int); 
void Set_thrird(int); 

//перегрузка операции присваивания 
three_nums& operator=(const three_nums&);

//глобальные операторы-функции ввода-вывода
friend istream& operator>>(istream&in, three_nums&c);
friend ostream& operator<<(ostream&out,const three_nums&c);

protected: int first; int second; int thrird;
};

