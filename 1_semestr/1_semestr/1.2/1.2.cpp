#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    float num1, num2;
    cout << "введите два числа через enter" << endl;
    cin >> num1 >> num2;
    if (num2 == 0) { cout << "и как ты предлагаешь мне на 0 делить?" << endl; }
    else { cout << "результат деления: " << num1 / num2 << endl; }
}