#pragma once

#include "Person.h"

class List
{
protected:
	Person** beg;
	int size;
	int cur;
public:
	List() : beg{ nullptr }, size{ 0 }, cur{ 0 } {}
	List(int size);
	~List();

	int operator()() const;

	void Add();
	void Del();
	void Show() const;
	void HandleEvent(const TEvent& e);
};