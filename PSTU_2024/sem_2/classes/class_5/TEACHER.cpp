#include <iostream>
#include "TEACHER.h"

using namespace std;

TEACHER::TEACHER(void)
{
	name = "name";
	age = 0;
	subject = "subject";
	hours = 0;
}
TEACHER::TEACHER(const string& name, int age, const string& subject, int hours) 
{
	this->name = name;
	this->age = age;
	this->subject = subject;
	this->hours = hours;
}
TEACHER::TEACHER(const TEACHER& obj)
{
	name = obj.name;
	age = obj.age;
	subject = obj.subject;
	hours = obj.hours;
}
TEACHER& TEACHER::operator = (const TEACHER& obj)
{
	if (&obj == this) return *this;
	name = obj.name;
	age = obj.age;
	subject = obj.subject;
	hours = obj.hours;
	return *this;
}
istream& operator>>(istream& in, TEACHER& T)
{
	cout << "name: "; in >> T.name;
	cout << "age: "; in >> T.age;
	cout << "subject: "; in >> T.subject;
	cout << "hours: "; in >> T.hours;
	return in;
}
ostream& operator<<(ostream& out, const TEACHER& T)
{
	out << "name: " << T.name << endl;
	out << "age: " << T.age << endl;
	out << "subject: " << T.subject << endl;
	out << "hours: " << T.hours << endl;
	return out;
}
void TEACHER::Show()
{
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "subject: " << subject << endl;
	cout << "hours: " << hours << endl;
}
void TEACHER::setName(const string& name) { this->name = name; }
void TEACHER::setAge(int age) { this->age = age; }
void TEACHER::setSubject(const string& subject) { this->subject = subject; }
void TEACHER::setHours(int hours) { this->hours = hours; }
const string& TEACHER::getName() { return name; }
int TEACHER::getAge() { return age; }
const string& TEACHER::getSubject() { return subject; }
int TEACHER::getHours() { return hours; }
void TEACHER::increaseHours() { ++hours; }
void TEACHER::decreaseHours() { --hours; }