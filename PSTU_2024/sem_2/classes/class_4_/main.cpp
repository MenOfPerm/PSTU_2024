#include <iostream>
#include "thee_nums.h"
#include "date.h"
using namespace std;

int main()
{

	three_nums a; 
	cin >> a; 
	cout << a; 
	three_nums b(99, 4, 115); 
	cout << b; 
	a = b; 
	cout << a;
	date c;//создать объект 
	cin>>c;//ввести значения атрибутов 
	cout<<c;//вывести значения атрибутов

}