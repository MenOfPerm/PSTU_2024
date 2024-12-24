#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");

    int N;
    cout << "введите число N" << endl;
    cin >> N;

    for (int i = 1; i <= N; i++) { cout << " *"; }
    cout <<endl;
    for (int i = 1; i <= N-2; i++) 
    {
        cout << " *";
        for (int i = 1; i <= N-2; i++) { cout << "  "; }
        cout << " *" << endl;
    }

    for (int i = 1; i <= N; i++) { cout << " *"; }
    return 1;
}