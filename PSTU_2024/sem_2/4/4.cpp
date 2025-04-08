#include <iostream>
#include <random>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    
    int arr[10]{};

    for (int i = 0; i < 10; ++i)
    {
        arr[i] = dist(gen);
        cout << arr[i] << ' ';
    }
    cout << endl;

    int arr_1[5];

    for (int i = 0; i < 5; ++i)
    {
        arr_1[i] = arr[i + 5];
        cout << arr_1[i] << ' ';
    }
    cout << endl;

    int arr_2[8];

    for (int i = 0; i < 5; ++i)
    {
        arr_2[i] = arr_1[i];
        cout << arr_2[i] << ' ';
    }

    for (int i = 5; i < 8; ++i)
    {
        arr_2[i] = dist(gen);
        cout << arr_2[i] << ' ';
    }
    cout << endl;
    
	return 0;
}