#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1; // ������ ��������, ������� ������ pivot (����� ��� ��������� ���������)
    for (int j = low; j <= high - 1; j++)
    {
        // ���� ������� ������� �������
        // ������ ��� ����� pivot
        if (arr[j] <= pivot)
        {
            i++; // ����������� ������ �������� ��������
            swap(arr[i], arr[j]); // ������ �������� �������
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);

}

/* ������� ���������� �� ������ */
void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;

    int pI = partition(arr, low, high);
    // ����� ����� ���������� arr[pI] ��� ����� � ���������� ����� � �������� �������
    // ��������� ����� ��������� �� pivot 
    quickSort(arr, low, pI - 1);
    // ��������� ����� ��������� ����� pivot
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