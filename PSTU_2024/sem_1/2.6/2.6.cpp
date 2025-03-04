#include <iostream>
using namespace std;
int main()
{
    int len;
    setlocale(LC_CTYPE, "rus");
    cout << "введите длинну катета (натуральное число больше 2.)" << endl;
    cin >> len;
    for (int i = 1; i <= len; i++)
    {
        for (int j = len - i; j >= 0; j--) { cout << "*"; }

        for (int k = i; k >= 1; k--) { cout << " "; }
        cout << "" << endl;
    }
    return 0;
}