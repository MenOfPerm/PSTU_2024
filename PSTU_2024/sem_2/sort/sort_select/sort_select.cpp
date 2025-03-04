#include <iostream>;
#include <cstdlib>// библиотека в которой хранятся функции рандома

#include <ctime> // содержит time()
using namespace std;
int main()
{
	int tmp;
	const int n = 7;
	//Заполнение массива случайными числами
	srand(time(NULL));
	int arr[n];
	int range_min, range_max;
	range_min = -300;
	range_max = 412;
	for (int i = 0; i < n; i++)
	{
		arr[i] = ((double)rand() / RAND_MAX) * (range_max -
			range_min) + range_min;// понятия не имею как это работает
		cout << arr[i] << " ";
	}
	// --------------------------------------------
	cout << endl;
	int min_index;
	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_index]) { min_index = j; }
		}
		tmp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = tmp;
	}
	//--------------------
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}