#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int N;
    cout << "������� ����� N (�����,������ 1)" << endl;
    cin >> N;
    do { cout << "������� ����� ������ 1!" << endl; cin >> N; } while (N == 1);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << " *";
        }
        cout << "\n";
    }
    return 1;

}