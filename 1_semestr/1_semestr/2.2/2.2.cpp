#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int lengh, answer = 1;
    std::cout << "введите число, сколько первых чисел перемножаем" << endl;
    cin >> lengh;

    for (int i = 1; i <= lengh; i++)
    {
        answer *= i;
    }

    cout << "произведение: " << answer << endl;
    return 0;
}