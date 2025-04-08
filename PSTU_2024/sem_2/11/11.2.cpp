// создать двунаправленный список
// удалить/добавить-------первый/последний/(где-то в середине)-----элементы
//вывести элементы , вывести конкретный элемент
#include <iostream>
#include<string>
using namespace std;


struct LIST_elem
{
	int data;
	LIST_elem* prev = nullptr;
	LIST_elem* next = nullptr;

};

struct Listt {

	int lenn;
	LIST_elem* first;
	LIST_elem* last;

	void init()
	{
		lenn = 0;
		first = nullptr;
		last = nullptr;
	}

	void add_elem(int poz,int d)// вставка нового элемента на определённую позицию
	{
		if (poz == lenn) { add_last_elem(d); return; }

		if (poz == 1) { add_first_elem(d); return; }

		LIST_elem* cur;
		if (poz >= (lenn/2))// определяем откуда нам ближе идте к позиции (идём с конца)
		{
			poz = lenn - poz;
			cur = this->last;

			for (int i = 0; i != poz+1; i++)
			{
				cur = cur->prev;
			}


		}
		else// (идём с начала)
		{
			cur = this->first;

			for (int i = poz-2; i != 0; i--)
			{
				cur = cur->next;
			}
		}
		LIST_elem* new_elem = new LIST_elem;// элемент вставки
		LIST_elem* temp = cur->next;// элемент на месте вставки
		new_elem->data = d;// записываем данные в наш новый элемент
		new_elem->next = temp;// записываем указатель на бывший элемент этой позиции
		new_elem->prev = cur;
		cur->next = new_elem;//
		

	}

	void add_first_elem(int d)
	{
		if (this -> lenn == 0) { first = last = new LIST_elem; first->data = d; }
		else
		{
			LIST_elem *temp = this->first;// сохраняем указатель на первый элемент

			first = new LIST_elem;// создаём новый элемент

			this->first = first;// делаем его первым в списке
			first->data = d;// записываем данные
			first->next = temp;// добавляем нашему новому началу указатель на след элемент
			temp->prev = first;// добавляем бывшему началу указатель на предыдущий элемент

			
		}
		lenn++;
	}
	void add_last_elem(int d)
	{
		if (this -> lenn == 0) { last = new LIST_elem; first->data = d; }
		else
		{
			LIST_elem* temp = this->last;// сохраняем указатель на последний элемент
			last = new LIST_elem;
			this->last = last;// делаем его последним в списке
			last->data = d;// записываем в новый последний элемент данные
			last->prev = temp;// добавляем нашему новому последнему указателю указатель на предыдущий последний элемент
			temp->next = last;// добавляем нашему бывшему последнему элементу указатель на след элемент ( наш новый последний элемент)

		}
	}

	void del_elem(int poz)
	{
		LIST_elem* cur;
		if (poz >= (lenn / 2))// определяем откуда нам ближе идте к позиции (идём с конца)
		{
			poz = lenn - poz;
			cur = this->last;

			for (int i = 0; i != poz +1 ; i++)
			{
				cur = cur->prev;
			}


		}
		else// (идём с начала)
		{
			cur = this->first;

			for (int i = poz - 2; i != 0; i--) { cur = cur->next; }
		}
		// cur - указатель на элемент перед удаляемым
		LIST_elem* del_elem = cur->next;// указатель на удаляемый элемент
		LIST_elem* after_del_elem = del_elem->next;// указатель на элемент после удаляемого
		cur->next = del_elem->next;// скрепляем через указатели элемент перед и после
		after_del_elem->prev = del_elem->prev;// скрепляем через указатели элемент после и перед

	}

	void print_out()
	{
		LIST_elem *unit = this->first;
		do
		{
			cout << unit->data;
			unit = unit->next;
		}while (unit->next != nullptr);// цикл while с пост условием (я уже и забыл как это делается)
		cout << unit -> data;
	}

	void find_in_list(int d)// поиск , есть ли в списке элемент с такими данными (мне лень что то сложное придумывать)
	{

		LIST_elem* unit = this->first;
		bool flag = false;
		int i;
		for (i = this -> lenn; i != 0; i--)
		{
			if (unit->data = d) flag = true;
		}
		if (flag) cout << "элемент с данным значение ПРИСУТСТВУЕТ с индексом: " << i << endl; 
		else cout << "элемент с данным значением ОТСУТСТВУЕТ в списке " << i << endl;
	}

	void print_one_elem(int ind)// вывод элемента с заданным индексом
	{

		LIST_elem* unit;
		if ((ind > (this->lenn)) or ind < 0) { cout << "этот индекс вне длинны списка" << endl; return; }
		if (this->lenn / 2 >= ind+1)
		{
			unit = this->last;
			for (int i = this->lenn; i != ind; i--)
			{
				unit = unit->prev;
			}
		}
		else
		{
			unit = this->first;
			for (int i = 0; i != ind-1; i++)
			{
				unit = unit->next;
			}
		}
		cout << unit->data << endl;
	}
};

int main()
{
	Listt myList;
	myList.init();
	myList.add_first_elem(10);
	myList.add_first_elem(20);
	myList.add_first_elem(30);
	myList.add_first_elem(40);
	myList.add_elem(2, 44);
	myList.print_one_elem(2);
	myList.print_one_elem(4);
	myList.print_out();
	return 0;
}







