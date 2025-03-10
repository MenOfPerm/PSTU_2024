// скопировать все строки в которых нет повтор€ющихс€ слов в файл 2
// определить количество гласных букв в первой строке файла 2 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int trash(string str_1)
{
	
	for (int i = 0; i <= str_1.length() - 1; i++)
	{
		string temp_1 = "";
		string temp_2 = "";
		while ((str_1[i] != ' '))
		{
			if (i == str_1.length())
			{
				break;
			}
			temp_1 += str_1[i];
			i++;
		}// нашЄл слово
		for (int e = i+1; e < str_1.length() - 1; e++)
		{
			while ((str_1[e] != ' '))
			{
				if (e == str_1.length())
				{
					break;
				}
				temp_2 += str_1[e];
				e++;
			}
			if (temp_1 == temp_2)return 1;
			temp_2 = "";
		}
		
		
	}
	return 0;
}
int main()
{
	string line;
	setlocale(LC_ALL, "RU");

	fstream myfile;
	ofstream myfile_2;
	myfile.open("text_1.txt");
	myfile_2.open("text_2.txt", ios::app);

	while (getline(myfile, line))
	{
		if (!trash(line)) 
		{ myfile_2 << line << endl; }
	}
	myfile.close();
	myfile_2.close();
	

}