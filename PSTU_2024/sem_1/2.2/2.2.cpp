#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int lengh, answer = 1;
    std::cout << "������� �����, ������� ������ ����� �����������" << endl;
    cin >> lengh;

    for (int i = 1; i <= lengh; i++)
    {
        answer *= i;
    }

    cout << "������������: " << answer << endl;
    return 0;
}