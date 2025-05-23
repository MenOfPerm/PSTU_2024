#include <iostream>
#include "Dialog.h"

using namespace std;

int main()
{
    cout << "Available commands:\n"
        << "mN - create group (N = size)\n"
        << "+ - add employee\n"
        << "- - remove last employee\n"
        << "s - show all\n"
        << "zN - show name at index N\n"
        << "q - quit\n";

    Dialog D;
    D.Execute();
    return 0;
}