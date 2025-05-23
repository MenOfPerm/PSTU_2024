#include "List.h"
#include "Event.h"
#include "Employee.h"
#include <iostream>

using namespace std;

List::List(int size)
{
	beg = new Person* [size];
	this->size = size;
	cur = 0;
}
List::~List()
{
	delete[] beg;
	beg = nullptr;
}
int List::operator()() const { return cur; }
void List::Add()
{
	if (cur < size) 
	{
		Employee* p = new Employee;
		p->Input();
		beg[cur++] = p;
	}
	else 
	{
		cout << "List is full!\n";
	}
}
void List::Del()
{
	if (cur > 0) --cur;
}
void List::Show() const
{
	if (cur == 0)
	{
		cout << "List is empty" << endl;
		return;
	}

	for (Person** p = beg; p<beg+cur; ++p)
	{
		(*p)->Show();
	}
}
void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage && e.command == cmGetName) 
	{
		int k = e.a;
		if (k >= 0 && k < cur) beg[k]->HandleEvent(e);
		else cout << "Invalid index!\n";
	}
}