#include <iostream>
#include<string>
using namespace std;
struct StackElem {
	int data;
	StackElem* next;
};
struct Stack {
	StackElem* top;
	int size;
	void init()
	{

		top = nullptr;
		size = 0;
	}
	void push(int data)
	{

		StackElem* cur = new StackElem;
		cur->data = data;
		cur->next = top;
		top = cur;
		size++;
	}
	int pop()
	{
		int value = top->data;
		StackElem* tmp = top;
		top = top->next;
		size--;
		delete tmp;
		return value;
	}
	StackElem* top() { return top; }
};
Stack createStack(int size)
{
	Stack stack{};
	stack.init();
	int data;

	for (int i = 0; i < size; i++)
	{
		cin >> data;
		stack.push(data);
	}
	return stack;
}

int main()
{




}