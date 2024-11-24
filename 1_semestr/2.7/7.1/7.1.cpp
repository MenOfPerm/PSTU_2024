#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");

    int N,LH;
    cout << "введите число N ,( извлекается из под корня, больше 3)" << endl;
    cin >> N;
    LH = sqrt(N);// длинна стороны
    for (int i = 1; i <= LH; i++)
    {
        for (int j = 1; j <= LH; j++)
        {
            cout << " *";
        }
        cout << "\n";
    }
    return 1;

}