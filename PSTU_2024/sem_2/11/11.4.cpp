
#include <iostream>
#include<string>
using namespace std;
struct QueueElem {
	int data;
	QueueElem* next;
};
struct Queue {
	QueueElem* front;
	QueueElem* back;
	int size;
	void init()
	{

		front = nullptr;
		back = front;
		size = 0;
	}

	void push(int data)
	{
		QueueElem* tmp = new QueueElem;
		tmp->data = data;
		tmp->next = nullptr;
		if (size == 0)
		{
			front = tmp;
			back = tmp;
		}
		else
		{
			back->next = tmp;
			back = tmp;
		}
		size++;
	}

	int pop()
	{
		int value = front->data;
		QueueElem* tmp = front;
		if (size == 1) { back = nullptr; }
		front = front->next;
		size--;
		delete tmp;
		return value;
	}
	QueueElem* front() { return front; }
	QueueElem* back() { return back; }

	Queue createQueue(int size)
	{
		Queue queue{};
		queue.init();
		int data;
		for (int i = 0; i < size; i++)
		{
			cin >> data;
			queue.push(data);
		}
		return queue;
	};
};

int main()
{


}