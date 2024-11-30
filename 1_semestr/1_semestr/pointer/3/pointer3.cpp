#include <iostream>
using namespace std;
int main()
{   
    float* std1, *std2;
    float num1, num2;
    cin >> num1 >> num2;
    std1 = &num1;
    std2 = &num2;

    cout << *std1 + *std2 << endl;
return 0;
}
