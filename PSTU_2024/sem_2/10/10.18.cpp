// сформировать массив строк 
// удалить из массива строки начинающиеся на а
#include <iostream>
#include<string>
#include<random>
using namespace std;


string randomStrGen(int max_length) {// генерация случайной строки взята с сайта: https://stackoverflow.com/questions/47977829/generate-a-random-string-in-c11 (ответил: Ahmed Osama)
    string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<> dist(0, possible_characters.size() - 1);
    string ret = "";
    for (int i = 0; i < max_length; i++) {
        int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
        ret += possible_characters[random_index];
    }
    return ret;
}

int main()
{
	int len,len_str,count_deleted = 0;
	setlocale(LC_ALL, "RU");
	cout << "введите длинну массива: " << endl;
	cin >> len; 
    cout << "введите длинну генерируемого элемента: " << endl;
    cin >> len_str;
    string* array = new string[len];
    
    for (int i = 0; i < len; i++)
    {
        array[i] = randomStrGen(len_str);
    }
    cout << " вот сгенерированный массив построчно:" << endl;
    for (int i = 0; i < len-1; i++)
    {
        cout << array[i] << endl;
    }
    for (int i = 0; i < len - 1; i++)
    {
        if (array[i][0]=='a')
        {
            for (int e = i; e < len - 2; e++)// смещаем элементы массива на 1 , удаляя элемент с а
            {
                array[e] = array[e + 1];
            }
            len--;// уменьшаем длиннну массива
        }
    }
    cout << "Вот тот же массив , только без строк начинающихся на а:" << endl;
    cout << "Он похудел на: "<< count_deleted << endl;
    for (int i = 0; i < len - 1; i++)
    {
        cout << array[i] << endl; count_deleted++;
    }
    delete[] array;
}