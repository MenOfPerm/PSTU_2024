#include <iostream>

using namespace std;

void shellSort(int arr[], int n)
{
	for (int h = n / 2; h >= 1; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			int key = arr[i];
			int j;

			for (j = i; j >= h && arr[j - h] > key; j -= h)
			{
				arr[j] = arr[j - h];
			}

			arr[j] = key;
		}
	}
}

int main()
{
	int arr[5]{ 1, 5, 4, 7, 2 };

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	shellSort(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}