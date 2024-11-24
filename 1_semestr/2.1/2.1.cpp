#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int lengh , answer = 0;
    std::cout << "введите число, сколько первых чисел считаем";
    cin >> lengh;

    for (int i = 1; i <= lengh; i++)
    {
        answer += i;
    }

    cout << "сумма: " << answer << endl;
    return 0;
}
