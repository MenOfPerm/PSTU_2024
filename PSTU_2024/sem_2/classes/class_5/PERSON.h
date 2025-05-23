#include <string>
#pragma once

using namespace std;

class PERSON
{
protected:
	string name = "";
	int age = 0;
public:
    PERSON(void) {};
    virtual void Show() = 0;
    virtual void setName(const string& name) = 0;
    virtual void setAge(int age) = 0;
    virtual const string& getName() = 0;
    virtual int getAge() = 0;
    virtual ~PERSON(void) {};
};