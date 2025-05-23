#pragma once

#include <string>
#include "Event.h"

using namespace std;

class Person
{
public:
	Person();
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual void HandleEvent(const TEvent& e) = 0;
	virtual ~Person();
protected:
	string name;
	int age;
};