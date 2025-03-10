// удалить слова в которых нет сочетания цифра+буква
#include <iostream>
#include<string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");
	string str;
	cout << "введите вашу строку"<<endl;
	getline(cin, str);
	int first;
	cout << str.length() << endl;
	for (int i = 0; i < str.length()-2; i++)// перебераем элементы
	{
		if (str[i]!=' ')
		{
			cout << i << endl;
			first = i;
			bool flag_digit = false;// флаг на наличие цифры в слове
			bool flag_isletter = false;//флаг на наличие буквы в слове
			while (str[i]!=' ')//проходим циклом по слову
			{
				if (str[i] == '.')break;
				if (isdigit(str[i]))flag_digit = true;
				if (!isdigit(str[i]))flag_isletter = true;
				i++;
			}
			if (flag_digit && flag_isletter){}// проверяем наличие 
			else//
			{
				str.erase(first, i-first+1);
				i = first;
			}
		}
	}

	str.insert(first, ".");//
	cout << str << endl;


}

