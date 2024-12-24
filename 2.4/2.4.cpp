#include <iostream>
using namespace std;
/*
Напечатать в консоли равнобедренный треугольник из
звездочек ( * ) с вершиной, направленной вверх, и основанием
N, где N — натуральное нечетное число больше 3.
*/
int main()
{
    int len, height,p;//длинна основания , высота , колво точек
    setlocale(LC_CTYPE, "rus");
    cout << "введите N — натуральное нечетное число больше 3" << endl;
    cin >> len;
    height = (len + 1) / 2;
    // (len + 1) / 2 высота
    p = 1;
    for (int i = 1; i <= height; i++)
    {
        for (int j = height - i; j >= 1; j--) { cout << " "; }

        for (int k = p; k >= 1;k--) { cout << "*"; }
        p = p + 2;
        cout << "" << endl;
    }

}
