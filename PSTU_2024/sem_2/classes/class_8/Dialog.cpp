#include "Dialog.h"
#include <iostream>

using namespace std;

void Dialog::GetEvent(TEvent& event)
{
    string input;
    cout << "> ";
    getline(cin, input);

    if (input.empty()) {
        event.what = evNothing;
        return;
    }

    char command = input[0];
    string param = input.substr(1);

    if (string("m+-szq").find(command) != string::npos) {
        event.what = evMessage;
        switch (command) {
        case 'm': event.command = cmMake; break;
        case '+': event.command = cmAdd; break;
        case '-': event.command = cmDel; break;
        case 's': event.command = cmShow; break;
        case 'z': event.command = cmGetName; break;
        case 'q': event.command = cmQuit; break;
        }

        if ((command == 'm' || command == 'z') && !param.empty()) {
            try {
                event.a = stoi(param);
            }
            catch (...) {
                event.a = 0;
            }
        }
    }
    else {
        event.what = evNothing;
    }
}

int Dialog::Execute()
{
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);

    } while (!Valid());
    return EndState;
}

void Dialog::HandleEvent(TEvent& event)
{
    if (event.what != evMessage) return;

    switch (event.command) {
    case cmMake:
        if (event.a <= 0) {
            cout << "Error: Group size must be positive!\n";
            break;
        }
        if (beg) delete[] beg;
        size = event.a;
        beg = new Person * [size];
        cur = 0;
        cout << "Created group with size " << size << endl;
        break;

    case cmAdd:
        Add();
        cout << "Employee added successfully\n";
        break;

    case cmDel:
        if (cur > 0) {
            Del();
            cout << "Last employee removed\n";
        }
        else {
            cout << "Error: Group is empty\n";
        }
        break;

    case cmShow:
        Show();
        break;

    case cmGetName:
        if (event.a >= 0 && event.a < cur) {
            List::HandleEvent(event);
        }
        else {
            cout << "Error: Invalid index\n";
        }
        break;

    case cmQuit:
        EndExec();
        break;

    default:
        cout << "Error: Unknown command\n";
    }

    ClearEvent(event);
}

void Dialog::ClearEvent(TEvent& event) { event.what = evNothing; }
int Dialog::Valid() const { return EndState; }
void Dialog::EndExec() { EndState = 1; }