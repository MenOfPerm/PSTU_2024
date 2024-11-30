
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int num1, num2, num3, max;
    cout << "введите 3 целых числа для сравнения через enter" << endl;
    cin >> num1 >> num2 >> num3;
    if (num1 >= num2) { max = num1; }
    else { max = num2; }
    if (max < num3) { max = num3; }
    cout << "максимальное число: " << max << endl;
    return 0;
}
