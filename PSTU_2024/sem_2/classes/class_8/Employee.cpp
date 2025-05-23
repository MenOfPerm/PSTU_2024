#include "Employee.h"
#include <iostream>

using namespace std;

Employee& Employee::operator=(const Employee& obj)
{
	if (this == &obj) return *this;
    name = obj.name;
    age = obj.age;
    salary = obj.salary;
    position = obj.position;
    return *this;
}
void Employee::setName(string n) { name = n; }
void Employee::setAge(int a) { age = a; }
void Employee::setSalary(float s) { salary = s; }
void Employee::setPosition(string p) { position = p; }
string Employee::getName() { return name; }
int Employee::getAge() { return age; }
float Employee::getSalary() { return salary; }
string Employee::getPosition() { return position; }
void Employee::Show()
{
	cout << "Name: " << name << 
            "\nAge: " << age << 
            "\nSalary: " << salary << 
            "\nPosition: " << position <<  "\n";
}
void Employee::Input()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter position: ";
    cin >> position;
}
void Employee::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage && e.command == cmGetName) 
    {
        cout << "Имя сотрудника: " << name << endl;
    }
}