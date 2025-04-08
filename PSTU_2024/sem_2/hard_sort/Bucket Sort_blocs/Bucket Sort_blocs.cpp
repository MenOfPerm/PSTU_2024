//Ѕлочна€ сортировка (Bucket Sort)
//или же карманна€ сортировкаї

#include <iostream>
using namespace std;

const int BUCKET_NUM = 10;
const int BUCKET_SIZE = 10;

int* bucketSort(int arr[], int n)
{
	int buckets[BUCKET_NUM][BUCKET_SIZE];

	// чтобы знать реальное число элементов в конкретном ведре и не 
	// вылезти за это число при операци€х внутри ведра
		int bucketSizes[BUCKET_NUM] = { 0 };

		// Ќаходим максимальный элемент дл€ правильного распределени€
		int max_val = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] > max_val) {
				max_val = arr[i];
			}
		}
		max_val++; // „тобы избежать делени€ на 0 и правильно распределить элементы

	// раскидываем элементы массива по ведрам
	for (int i = 0; i < n; i++)
	{
		int bucketIndex = (arr[i] * BUCKET_NUM) / max_val;
		buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
		bucketSizes[bucketIndex]++;
	}

	// сортируем каждое ведро
	for (int i = 0; i < BUCKET_NUM; i++)
	{
		// берем сортировку вставками или любую другую
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			int tmp = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > tmp)
			{
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = tmp;
		}
	}
	// складываем элементы в исходный массив
	int idx = 0;
	for (int i = 0; i < BUCKET_NUM; i++)
	{
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			arr[idx++] = buckets[i][j];
		}
	}
	return arr;
}

int main()
{
	int arr[10] = { 123,432,111,3,22,43,5,6567,123,4 };
	bucketSort(arr,10);
}
