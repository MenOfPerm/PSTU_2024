#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1; // индекс элемента, который меньше pivot (чтобы его поставить правильно)
    for (int j = low; j <= high - 1; j++)
    {
        // если текущий элемент массива
        // меньше или равен pivot
        if (arr[j] <= pivot)
        {
            i++; // увеличиваем индекс меньшего элемента
            swap(arr[i], arr[j]); // меняем элементы местами
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);

}

/* Быстрая сортировка по Ломуто */
void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;

    int pI = partition(arr, low, high);
    // после этого разделения arr[pI] уже будет в правильном месте в исходном массиве
    // сортируем часть элементов до pivot 
    quickSort(arr, low, pI - 1);
    // сортируем часть элементов после pivot
    quickSort(arr, pI + 1, high);

}

int main()
{
    int arr[7] = { 123,4412,1,2345,2333,543,555 };
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }

}