#pragma once

#include "Event.h"
#include "List.h"

class Dialog :
	public List
{
protected:
	int EndState;
public:
	Dialog() : List() { EndState = 0; }
	virtual ~Dialog() {}
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid() const;
	void EndExec();
	void EventError(TEvent& event);
};