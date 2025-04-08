// ������� ��������������� ������
// �������/��������-------������/���������/(���-�� � ��������)-----��������
//������� �������� , ������� ���������� �������
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

	void add_elem(int poz,int d)// ������� ������ �������� �� ����������� �������
	{
		if (poz == lenn) { add_last_elem(d); return; }

		if (poz == 1) { add_first_elem(d); return; }

		LIST_elem* cur;
		if (poz >= (lenn/2))// ���������� ������ ��� ����� ���� � ������� (��� � �����)
		{
			poz = lenn - poz;
			cur = this->last;

			for (int i = 0; i != poz+1; i++)
			{
				cur = cur->prev;
			}


		}
		else// (��� � ������)
		{
			cur = this->first;

			for (int i = poz-2; i != 0; i--)
			{
				cur = cur->next;
			}
		}
		LIST_elem* new_elem = new LIST_elem;// ������� �������
		LIST_elem* temp = cur->next;// ������� �� ����� �������
		new_elem->data = d;// ���������� ������ � ��� ����� �������
		new_elem->next = temp;// ���������� ��������� �� ������ ������� ���� �������
		new_elem->prev = cur;
		cur->next = new_elem;//
		

	}

	void add_first_elem(int d)
	{
		if (this -> lenn == 0) { first = last = new LIST_elem; first->data = d; }
		else
		{
			LIST_elem *temp = this->first;// ��������� ��������� �� ������ �������

			first = new LIST_elem;// ������ ����� �������

			this->first = first;// ������ ��� ������ � ������
			first->data = d;// ���������� ������
			first->next = temp;// ��������� ������ ������ ������ ��������� �� ���� �������
			temp->prev = first;// ��������� ������� ������ ��������� �� ���������� �������

			
		}
		lenn++;
	}
	void add_last_elem(int d)
	{
		if (this -> lenn == 0) { last = new LIST_elem; first->data = d; }
		else
		{
			LIST_elem* temp = this->last;// ��������� ��������� �� ��������� �������
			last = new LIST_elem;
			this->last = last;// ������ ��� ��������� � ������
			last->data = d;// ���������� � ����� ��������� ������� ������
			last->prev = temp;// ��������� ������ ������ ���������� ��������� ��������� �� ���������� ��������� �������
			temp->next = last;// ��������� ������ ������� ���������� �������� ��������� �� ���� ������� ( ��� ����� ��������� �������)

		}
	}

	void del_elem(int poz)
	{
		LIST_elem* cur;
		if (poz >= (lenn / 2))// ���������� ������ ��� ����� ���� � ������� (��� � �����)
		{
			poz = lenn - poz;
			cur = this->last;

			for (int i = 0; i != poz +1 ; i++)
			{
				cur = cur->prev;
			}


		}
		else// (��� � ������)
		{
			cur = this->first;

			for (int i = poz - 2; i != 0; i--) { cur = cur->next; }
		}
		// cur - ��������� �� ������� ����� ���������
		LIST_elem* del_elem = cur->next;// ��������� �� ��������� �������
		LIST_elem* after_del_elem = del_elem->next;// ��������� �� ������� ����� ����������
		cur->next = del_elem->next;// ��������� ����� ��������� ������� ����� � �����
		after_del_elem->prev = del_elem->prev;// ��������� ����� ��������� ������� ����� � �����

	}

	void print_out()
	{
		LIST_elem *unit = this->first;
		do
		{
			cout << unit->data;
			unit = unit->next;
		}while (unit->next != nullptr);// ���� while � ���� �������� (� ��� � ����� ��� ��� ��������)
		cout << unit -> data;
	}

	void find_in_list(int d)// ����� , ���� �� � ������ ������� � ������ ������� (��� ���� ��� �� ������� �����������)
	{

		LIST_elem* unit = this->first;
		bool flag = false;
		int i;
		for (i = this -> lenn; i != 0; i--)
		{
			if (unit->data = d) flag = true;
		}
		if (flag) cout << "������� � ������ �������� ������������ � ��������: " << i << endl; 
		else cout << "������� � ������ ��������� ����������� � ������ " << i << endl;
	}

	void print_one_elem(int ind)// ����� �������� � �������� ��������
	{

		LIST_elem* unit;
		if ((ind > (this->lenn)) or ind < 0) { cout << "���� ������ ��� ������ ������" << endl; return; }
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







