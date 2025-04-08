// ������� ���������������� ������
// �������/��������-------������/���������/(���-�� � ��������)-----��������
//������� �������� , ������� ���������� �������
#include <iostream>
#include <fstream>
#include<string>

using namespace std;

struct ListElem {
	int data;
	ListElem* next;
};
ListElem* del_elem(ListElem *start ,int n)
{
	ListElem *cur,*del;// � ������� ��������
	cur = start;// ��� ���� ������ ��� ��������?
	int i = 0;

	while (i < n-2)
	{
		cur = cur->next;
		i++;
	}// ������� �� �������� ����� ���������
	
	del = cur -> next;// ���� ��������� �� ��������� �������
	if (cur->next != nullptr) 
	{
		del->data = NULL;// ������� ������
		cur->next = del->next;// �������� ��������� �� �������� �������� �� ��������� ����������
		del->next = nullptr;// ������� ��������� � ��������� ��������
		
	}
	else
	{
		cout<<"�� ���� ������� �� ������������ �������" << endl;
	}
	return start;
}
ListElem* del_first_elem(ListElem *start)
{
	ListElem *temp;
	temp = start -> next;
	start -> data = NULL;
	start -> next = nullptr;
	return temp;
}

ListElem* add_elem(ListElem *start, int n, int d)
{	
	ListElem *new_elem, *cur;
	new_elem = new ListElem;
	new_elem->data = d;
	cur = start;
	bool flag = true;
	for (int i = 0; i < n-2; i++)// �� �� ��� �� ������� ������� �������������� �������
	{
		if (cur->next != nullptr)  cur = cur -> next; 
		else { cout << "�� ���� �������� ������� �� ��� �����, ������ ����� � ��� ������ ��������� ��� �� �����" << endl; flag = false; break; }
	}
	if (flag)
	{
		new_elem->next = cur->next;
		cur->next = new_elem;
	}
	return start;
}

ListElem* add_first_elem(ListElem* start, int d)
{
	ListElem* new_start;
	new_start = new ListElem;
	new_start -> data = d;
	new_start -> next = start;
	return new_start;
}


ListElem* createList(int n, int data = 0)// ������� �������� ������
{
	ListElem* start;
	ListElem* cur;
	ListElem* prev;
	start = new ListElem;
	if (data!= 0) { start->data = data; }
	else cin >> start -> data;

	start -> next = nullptr;
	prev = start;

	for (int i = 0; i < n - 1; i++)
	{
		cur = new ListElem;
		cin >> cur -> data;
		cur -> next = nullptr;
		prev -> next = cur;
		prev = cur;
	}
return start;
}

void print_list(ListElem* out)
{
	bool flag = true;
	while (flag)
	{
		cout <<" " << out->data ;
		if (out->next != nullptr) out = out->next;
		else flag = false;

	}
	cout << endl;
}

void recordToFile(ListElem* first_elem)
{
	ofstream myfile;
	myfile.open("list.txt");
	if (myfile.is_open())
	{
		bool flag = true;
		while (flag)
		{
			myfile << first_elem->data << endl;;
			if (first_elem->next != nullptr) first_elem = first_elem->next;
			else flag = false;
		}
		myfile.close();
	}
}

ListElem* getFromFile(string ful_name)
{
	ifstream myfile;
	myfile.open(ful_name);
	ListElem* first_elem_list = nullptr;
	if (myfile.is_open())
	{
		string line;
		getline(myfile, line); 
		/*int num= NULL;
		for (int i = 0; i < line.size(); i++)
		{
			num = num + (line[i] + '0');
		}*/
		int num = stoi(line);
		first_elem_list = createList(1,num);
		int e = 2;
		while (getline(myfile, line))
		{
			int num = NULL;
			
			//for (int i = 0; i < line.size(); i++) {num = num + (line[i] + '0');}
			num = stoi(line);
			add_elem(first_elem_list, e, num);
			e++;
		}
		myfile.close();
	}
	return first_elem_list;

}
void delet(ListElem* first_elem_del)
{
	ListElem* temp_first_elem_del;
	bool flag = true;
	while (flag)
	{
		if (first_elem_del->next != nullptr) 
		{
			temp_first_elem_del = first_elem_del->next; delete(first_elem_del); first_elem_del = temp_first_elem_del;
		}
		else flag = false;
	}

}

int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	cout << "������� ��������� ����� � ������( ������ 4)?" << endl;
	cin >> n;
	cout << "������� ��������(����� ����� enter)" << endl;
	ListElem* listoc = createList(n);
	cout << "��� ������"<< endl;
	print_list(listoc);

	listoc = del_first_elem(listoc);
	cout << "������ ������ �������" << endl;
	print_list(listoc);

	listoc = add_first_elem(listoc,77);
	cout << "������� �� ������ ����� 77" << endl;
	print_list(listoc);

	listoc = del_elem(listoc, 3);
	cout << "������ 3 �������" << endl;
	print_list(listoc);

	cout << "������� ������� ����� 2 � 3" << endl;
	listoc = add_elem(listoc,3, 3999);

	print_list(listoc);
	recordToFile(listoc);
	delet(listoc);
	listoc = getFromFile("list.txt");
	print_list(listoc);

}