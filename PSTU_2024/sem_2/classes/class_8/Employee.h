#pragma once

#include "Person.h"

class Employee :
	public Person
{
public:
	Employee() : salary{ 0 }, position{ "" } {}
	Employee(string n, int a, float s, string p) : salary{ s }, position{ p }
	{
		name = n;
		age = a;
	}
	~Employee() {}
	
	Employee(const Employee& obj) : salary{ obj.salary }, position{ obj.position } 
	{
		name = obj.name;
		age = obj.age;
	}
	Employee& operator=(const Employee& obj);

	void setName(string n);
	void setAge(int a);
	void setSalary(float a);
	void setPosition(string p);

	string getName();
	int getAge();
	float getSalary();
	string getPosition();
	void HandleEvent(const TEvent& e);

	void Show() override;
	void Input() override;
private:
	float salary;
	string position;
};