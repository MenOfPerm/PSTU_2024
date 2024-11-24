
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int lengh, answer = 0, temp = 1;
    cout << "введите число, больше 0" << endl;
    cin >> lengh;

    for (int i = 2; i <= lengh; i++)
    {
        temp *= i;
        answer += temp;
    }

    cout << answer << endl;
    return 0;
}

