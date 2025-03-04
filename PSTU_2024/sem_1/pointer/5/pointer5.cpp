#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    unsigned int n,f=1;
    unsigned int *ptr=&f;
    //cout << "введите положительное число" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        *ptr *= i;
    }
    cout << "число: " << n << " факториал: " << f << endl;
    return 0;
}

