//дл€ массива целых чисел найти макс элем
// дл€ строки найти длинну самого длинного слова
//7.18

#include <iostream>
#include<string>
using namespace std;



int trash(int a[7]) 
{
	int maxx = a[0];
	for (int i = 1; i < 6; i++)
	{
		if (a[i] > maxx) maxx = a[i];

	}
	return maxx;
}

int trash(string str)
{
	int len = 0;
	int len_temp = 0;
	for (int i = 0; i < str.length() - 1; i++)
	{
		while ((str[i] != ' '))
		{
			if (i== str.length() - 1)
			{
				break;
			}
			len_temp++;
			i++;
		}
		if (len_temp > len)len = len_temp;
		len_temp = 0;
	}
	return len;
}


int main()
{	

	setlocale(LC_ALL, "RU");
	int a[7] = {123,123,345,568345,6990,-1235,346};
	string b = "лодочка плывЄт, плывЄт и јјјјјјјјјјјјјјјјјјјјјјјјјјј.";
	cout << "программа обработает строку: \n\"" << b <<'\"' << endl;
	cout << "и целочисленный массив: " << "123,123,345,568345,6990,-1235,346" << endl << endl;
	cout <<"максимальный элемент массива: "<< trash(a) << endl;
	cout <<"длинна самого длинного слова: "<< trash(b) << endl;




}