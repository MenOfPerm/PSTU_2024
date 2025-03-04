#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int id_oper;
    float num_1, num_2, answer;
    cout << "Введите номер операции (1 = +,2 = -,3 = *,4 = /)" << endl;
    cin >> id_oper;
    cout << "Введите ДВА числа с которыми работаем, через ENTER" << endl;
    cin >> num_1 >> num_2;
    switch (id_oper)
    {
    case 1:answer = num_1 + num_2; break;
    case 2:answer = num_1 - num_2; break;
    case 3:answer = num_1 * num_2; break;
    case 4:answer = num_1 / num_2; break;
    default: cout << "первым можно вводить только целое число, ОТ 1 ДО 4 (ВКЛЮЧИТЕЛЬНО)" << endl; return 1;
    }
    cout << "результат вычисления: "<< answer << endl; //я ведь инициализирую answer в кейсах, разве нет?
    return 1;
}