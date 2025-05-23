#include <string>
#include "PERSON.h"
#pragma once

using namespace std;

class TEACHER : public PERSON
{
private:
	string subject;
	int hours;
public:
	TEACHER(void);
	TEACHER(const string& name, int age, const string& subject, int hours);
	TEACHER(const TEACHER& obj);
	~TEACHER(void) {};
	TEACHER& operator = (const TEACHER& obj);
	friend istream& operator>>(istream& in, TEACHER& T);
	friend ostream& operator<<(ostream& out, const TEACHER& T);
public:
	void Show() override;
	void setName(const string& name) override;
	void setAge(int age) override;
	void setSubject(const string& subject);
	void setHours(int hours);
	const string& getName() override;
	int getAge() override;
	const string& getSubject();
	int getHours();
	void increaseHours();
	void decreaseHours();
};